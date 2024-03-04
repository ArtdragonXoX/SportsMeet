//链表的迭代器
#pragma once
#include "List.h"

typedef struct
{
    int serial;
    void* data;
    ListNode* nextNode;
}Iterator;

Iterator* InitIterator(List* list);

void IteratorNextNode(Iterator* it);

void* IteratorData(Iterator* it);

int IteratorSerial(Iterator* it);

void FreeIterator(Iterator* it);