//学生-比赛信息表
#pragma once

#include "List.h"
#include "Iterator.h"

typedef struct
{
    int student;
    int match;
    int result; //成绩记录
}SMData;

void InitSMList();

int InsertNextSMData(int student,int match);

int InsertNextSMDataNode(SMData* data);

SMData* GetSMData(int serial);

int RecordResult(int serial,int result);

Iterator* GetSMListIterator();