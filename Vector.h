#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    int serial;
    void* data;
}VectorNode;

typedef struct
{
    int size;
    int serial;
    int ptr;
    VectorNode** array;
}Vector;

VectorNode* InitVectorNode();

Vector* InitVector();

VectorNode* GetVectorNode(Vector* vector,int serial);

int GetVectorNodePtr(Vector* vector,int serial);

int InsertNextVectorData(Vector* vector,void* data);

int InsertNextVectorNode(Vector* vector,VectorNode* node);

void* DeleteVectorNode(Vector* vector,int serial);

void InflateVector(Vector* vector);