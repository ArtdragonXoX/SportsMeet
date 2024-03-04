//学生-单位信息表
#pragma once

#include "List.h"
#include "Iterator.h"

typedef struct
{
    int student;
    int organization;
}SOData;

void InitSOList();

int InsertNextSOData(int student,int match);

int InsertNextSODataNode(SOData* data);

SOData* GetSOData(int serial);

Iterator* GetSOListIterator();