#include <stdlib.h>
#include "SList.h"

void slist_init(SList *list, destructor_func destructor)
{
    slist_head(list) = NULL;
    slist_tail(list) = NULL;
    slist_size(list) = 0;
    list->destroy    = destructor;
    list->match      = NULL;
}

void slist_destroy(SList *list)
{
    void *data;

    while (slist_size(list) > 0)
    {
        if (slist_remove_after(list, NULL, &data) == 0 && list->destroy != NULL)
        {
            list->destroy(data);
        }
    }
}

int slist_insert_after(SList *list, SListNode *node, void *data)
{
    SListNode *newNode = malloc(sizeof(*newNode));

    if (newNode == NULL)
    {
        return 1;
    }

    slist_data(newNode) = data;

    if (node == NULL)
    {
        slist_next(newNode) = slist_head(list);
        slist_head(list) = newNode;

        if (slist_size(list) == 0)
        {
            slist_tail(list) = newNode;
        }
    }
    else
    {
        slist_next(newNode) = slist_next(node);
        slist_next(node) = newNode;

        if (slist_next(newNode) == NULL)
        {
            slist_tail(list) = newNode;
        }
    }

    slist_size(list) = slist_size(list) + 1;

    return 0;
}

int slist_remove_after(SList *list, SListNode *node, void **data)
{
    if (slist_size(list) == 0)
    {
        return 1;
    }

    SListNode *remNode;

    if (node == NULL)
    {
        remNode = slist_head(list);
        slist_head(list) = slist_next(slist_head(list));

        if (slist_size(list) == 1)
        {
            slist_tail(list) = NULL;
        }
    }
    else
    {
        if (slist_next(node) == NULL)
        {
            return 1;
        }

        remNode = slist_next(node);
        slist_next(node) = slist_next(slist_next(node));

        if (slist_next(node) == NULL)
        {
            slist_tail(list) = node;
        }
    }

    *data = slist_data(remNode);
    free(remNode);
    slist_size(list) = slist_size(list) - 1;

    return 0;
}
