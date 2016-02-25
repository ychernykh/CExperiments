#include <stdlib.h>
#include "DList.h"

void dlist_init(DList *list, destructor_func destructor)
{
    list->head    = NULL;
    list->tail    = NULL;
    list->size    = 0;
    list->destroy = destructor;
    list->match   = NULL;
}

void dlist_destroy(DList *list)
{
    list->size = 0;
}

int  dlist_insert_after(DList *list, DListNode *node, void *data)
{
    if (node == NULL && list->size != 0)
    {
        return 1;
    }

    DListNode *newNode = malloc(sizeof(*newNode));

    if (!newNode)
    {
        return 1;
    }

    newNode->data = data;

    if (list->size == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = node->next;
        newNode->prev = node;

        if(node->next)
        {
            node->next->prev = newNode;
        }
        else
        {
            list->tail = newNode;
        }

        node->next = newNode;
    }

    list->size++;

    return 0;
}

int  dlist_insert_before(DList *list, DListNode *node, void *data)
{
    if (node == NULL && list->size != 0)
    {
        return 1;
    }

    DListNode *newNode = malloc(sizeof(*newNode));

    if (!newNode)
    {
        return 1;
    }

    newNode->data = data;

    if (list->size == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = node;
        newNode->prev = node->prev;

        if (node->prev)
        {
            node->prev->next = newNode;
        }
        else
        {
            list->head = newNode;
        }

        node->prev = newNode;
    }

    list->size++;

    return 0;
}

int  dlist_remove(DList *list, DListNode *node, void **data)
{
    if (node == NULL || list->size == 0)
    {
        return 1;
    }

    if (node->prev)
    {

    }

    *data = NULL;

    return 0;
}
