#include "Iterator.h"

Iterator *InitIterator(ListNode *list)
{
    Iterator* iterator=(Iterator*)malloc(sizeof(Iterator));
    iterator->node=list->nextNode;
}

void IteratorNextNode(Iterator *it)
{
    if(it->node!=NULL)
        it->node=it->node->nextNode;
}

void *IteratorData(Iterator *it)
{
    if(it->node==NULL)
        return NULL;
    return it->node->data;
}

void FreeIterator(Iterator *it)
{
    free(it);
}
