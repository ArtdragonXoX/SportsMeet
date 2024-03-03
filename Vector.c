#include "Vector.h"

#define InitLength 10
#define IncreaseLength 10

VectorNode *InitVectorNode()
{
    VectorNode* node=(VectorNode*)malloc(sizeof(VectorNode));
    node->serial=0;
    node->data=NULL;
    return node;
}

Vector *InitVector()
{
    Vector* vector=(Vector*)malloc(sizeof(Vector));
    vector->size=InitLength;
    vector->serial=0;
    vector->ptr=0;
    int size=sizeof(VectorNode*)*InitLength;
    vector->array=(VectorNode**)malloc(size);
    memset(vector->array,NULL,size);
    return vector;
}

VectorNode *GetVectorNode(Vector *vector, int serial)
{
    int ptr=GetVectorNodePtr(vector,serial);
    return vector->array[ptr];
}

int GetVectorNodePtr(Vector *vector, int serial)
{
        int low=0,high=vector->ptr;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int seek=vector->array[mid]->serial;
        if(seek>serial)
            high=mid-1;
        else if(seek<serial)
            low=mid+1;
        else
            return mid;
    }
    return 0;
}

int InsertNextVectorData(Vector *vector, void *data)
{
    VectorNode* node=InitVectorNode();
    node->data=data;
    return InsertNextVectorNode(vector,node);
}

int InsertNextVectorNode(Vector *vector, VectorNode *node)
{
    if(vector==NULL||node==NULL)
        return 0;
    if(vector->ptr>=vector->size)
        InflateVector(vector);
    node->serial=++vector->serial;
    vector->array[vector->ptr++]=node;
    return 1;
}