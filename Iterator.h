//链表的迭代器
#pragma once
#include "List.h"

typedef struct
{
    ListNode* node;
}Iterator;

//迭代器初始化
Iterator* InitIterator(ListNode* list);

//迭代器指向下一个节点
void IteratorNextNode(Iterator* it);

//获得迭代器指向节点的数据
void* IteratorData(Iterator* it);

//释放迭代器
void FreeIterator(Iterator* it);