#pragma once
#include <stdio.h>
#include <malloc.h>

typedef void (*DeleteFun_t)(void*);

typedef int (*SearchFun_t)(void*,void*);

typedef struct _ListNode
{
    void* data;
    struct _ListNode* nextNode;
}ListNode;

//链表初始化
ListNode* InitList();

//获得索引为serial的节点
ListNode* GetListNode(ListNode* list,int serial);

void* GetListNodeData(ListNode* list,int serial);

//获得索引为serial的前置节点
ListNode* GetPriorListNode(ListNode* list,int serial);

//插入数据
int InsertNextListData(ListNode*list, void* data);

//删除数据，需传入删除函数
void DeleteListNode(ListNode* list, int serial, DeleteFun_t fun_t);

//获得节点数
int NumberOfList(ListNode* list);

//寻找数据，返回索引，需传入寻找函数
int SearchData(ListNode* list,void* data,SearchFun_t fun_t);