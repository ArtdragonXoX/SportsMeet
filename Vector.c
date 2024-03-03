#include "Vector.h"

#define InitLength 10
#define IncreaseLength 10

VectorNode *InitVectorNode()
{
    VectorNode *node = (VectorNode *)malloc(sizeof(VectorNode));
    node->serial = 0;
    node->data = NULL;
    return node;
}

VectorNode **InitVectorNodeArray(int size)
{
    VectorNode **array = (VectorNode **)malloc(sizeof(VectorNode *) * size);
    memset(array, NULL, sizeof(VectorNode *) * size);
    return array;
}

Vector *InitVector()
{
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    vector->size = InitLength;
    vector->serial = 0;
    vector->ptr = 0;
    vector->array = InitVectorNodeArray(InitLength);
    return vector;
}

VectorNode *GetVectorNode(Vector *vector, int serial)
{
    int ptr = GetVectorNodePtr(vector, serial);
    return vector->array[ptr];
}

int GetVectorNodePtr(Vector *vector, int serial)
{
    int low = 0, high = vector->ptr;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int seek = vector->array[mid]->serial;
        if (seek > serial)
            high = mid - 1;
        else if (seek < serial)
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

int InsertNextVectorData(Vector *vector, void *data)
{
    VectorNode *node = InitVectorNode();
    node->data = data;
    return InsertNextVectorNode(vector, node);
}

int InsertNextVectorNode(Vector *vector, VectorNode *node)
{
    if (vector == NULL || node == NULL)
        return 0;
    if (vector->ptr >= vector->size)
        InflateVector(vector);
    node->serial = ++vector->serial;
    vector->array[vector->ptr++] = node;
    return 1;
}

void *DeleteVectorNode(Vector *vector, int serial)
{
    int ptr = GetVectorNodePtr(vector, serial);
    void *deleteData = vector->array[ptr]->data;
    free(vector->array[ptr]);
    for (int i = ptr; i < vector->ptr; ++i)
        vector->array[i] = vector->array[i + 1];
    --ptr;
    return deleteData;
}

void InflateVector(Vector *vector)
{
    VectorNode **array = InitVectorNodeArray(vector->size + IncreaseLength);
    for (int i = 0; i < vector->ptr; ++i)
    {
        array[i] = vector->array[i];
    }
    free(vector->array);
    vector->array = array;
}