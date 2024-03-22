#include "List.h"

ListNode *InitList()
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = NULL;
    node->nextNode = NULL;
    return node;
}

ListNode *GetListNode(ListNode *listNode, int serial)
{
    if (serial < 0)
        return NULL;
    if(serial==0)
        return listNode;
    ListNode *node = listNode->nextNode;
    for (int i = 1; i < serial; ++i)
    {
        node = node->nextNode;
        if (node == NULL)
            break;
    }
    return node;
}

void *GetListNodeData(ListNode *list, int serial)
{
    return GetListNode(list,serial)->data;
}

ListNode *GetPriorListNode(ListNode *listNode, int serial)
{
    return GetListNode(listNode, serial - 1);
}

int InsertNextListData(ListNode *listNode, void *data)
{
    ListNode *newNode = InitList();
    newNode->data = data;
    if (listNode->nextNode == NULL)
    {
        listNode->nextNode = newNode;
        return 1;
    }
    ListNode *node = listNode->nextNode;
    while (node->nextNode != NULL)
        node = node->nextNode;
    node->nextNode = newNode;
    return 1;
}

void DeleteListNode(ListNode *listNode, int serial, DeleteFun_t fun_t)
{
    ListNode *priorNode = GetPriorListNode(listNode, serial);
    if (priorNode == NULL)
        return;
    ListNode *deleteNode = priorNode->nextNode;
    void *data = deleteNode->data;
    priorNode->nextNode = deleteNode->nextNode;
    free(deleteNode);
    fun_t(data);
}

int NumberOfList(ListNode *listNode)
{
    int res = 0;
    ListNode *nowNode = listNode->nextNode;
    while (nowNode != NULL)
    {
        nowNode = nowNode->nextNode;
        ++res;
    }
    return res;
}

int SearchData(ListNode *list, void *data, SearchFun_t fun_t)
{
    int res = 1;
    ListNode *node = list->nextNode;
    while (node != NULL)
    {
        if (fun_t(node->data,data))
        {
            return res;
        }
        node = node->nextNode;
        ++res;
    }
    return -1;
}
