#pragma once
#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int serial;
    void* data;
    ListNode* nextNode;
}ListNode;

typedef struct
{
    int serial;
    ListNode* headNode;
}List;

ListNode* InitListNode();

List* InitList();

ListNode* GetListNode(List* list,int serial);

ListNode* GetPriorListNode(List* list,int serial);

int InsertNextListData(List *list, void* data);

int InsertNextListNode(List* list,ListNode* node);

void* DeleteListNode(List* list,int serial);

int NumberOfList(List* list);