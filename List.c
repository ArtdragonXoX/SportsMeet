#include "List.h"

ListNode* InitListNode()
{
    ListNode* node=(ListNode*)malloc(sizeof(ListNode));
    node->serial=0;
    node->data=NULL;
    node->nextNode=NULL;
    return node;
}

List *InitList()
{
    List* list=(List*)malloc(sizeof(List));
    list->headNode=NULL;
    list->serial=0;
    return list;
}

ListNode *GetListNode(List *list, int serial)
{
    ListNode* priorNode=GetPriorListNode(list,serial);
    if(priorNode==NULL)
        return NULL;
    return priorNode->nextNode;
}

ListNode *GetPriorListNode(List *list, int serial)
{
    if(serial>list->serial)
        return NULL;
    ListNode* nowNode=list->headNode;
    while(nowNode->nextNode!=NULL&&nowNode->nextNode->serial!=serial)
        nowNode=nowNode->nextNode;
    if(nowNode->nextNode==NULL)
        return NULL;
    return nowNode;
}

int InsertNextListData(List *list, void *data)
{
    ListNode* node=InitListNode();
    node->data=data;
    return InsertNextListNode(list,node);
}

int InsertNextListNode(List *list, ListNode *node)
{
    if(list==NULL||node==NULL)
        return 0;
    if(list->headNode==NULL)
    {
        list->headNode=node;
        node->serial=++list->serial;
        return 1;
    }
    ListNode* nowNode=list->headNode;
    while(nowNode->nextNode!=NULL)
        nowNode=nowNode->nextNode;
    nowNode->nextNode=node;
    return 1;
}

void *DeleteListNode(List *list,int serial)
{
    ListNode* priorNode=GetPriorListNode(list,serial);
    if(priorNode==NULL)
        return NULL;
    ListNode* deleteNode=priorNode->nextNode;
    void* data=deleteNode;
    priorNode->nextNode=deleteNode->nextNode;
    free(deleteNode);
    return data;
}

int NumberOfList(List *list)
{
    int res=0;
    ListNode* nowNode=list->headNode;
    while(nowNode!=NULL)
    {
        nowNode=nowNode->nextNode;
        ++res;
    }
    return res;
}
