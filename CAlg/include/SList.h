#ifndef SLIST_H__
#define SLIST_H__

#include <stddef.h>
#include "Utils.h"

/// Single linked list node.
struct SListNode_
{
    /// Pointer to next node, NULL if there is no next node.
    struct SListNode_ *next;

    /// Pointer to data.
    void              *data;
};

typedef struct SListNode_ SListNode;

/// Single linked list.
struct SList_
{
    /// Number of nodes.
    size_t           size;

    /// Function for testing equality of data.
    eq_func          match;

    /// Function for destroying data when
    /// deleting list.
    destructor_func  destroy;

    /// Pointer to head node.
    SListNode       *head;

    /// Pointer to tail node.
    SListNode       *tail;
};

typedef struct SList_ SList;

/// Initializes SList structure.
extern void slist_init(SList *list, destructor_func destructor);

/// Destroys list with all it's data.
extern void slist_destroy(SList *list);

/// Inserts new node after existing node, if node == NULL then inserts before head node.
/// Returns 0 if success or 1 on fail.
extern int  slist_insert_after(SList *list, SListNode *node, void *data);

/// Removes node after existing node, if node == NULL then removes head node.
/// Returns 0 if success or 1 on fail.
extern int  slist_remove_after(SList *list, SListNode *node, void **data);

/// List size macro.
#define     slist_size(list) ((list)->size)

/// List head macro.
#define     slist_head(list) ((list)->head)

/// List tail macro.
#define     slist_tail(list) ((list)->tail)

/// Node data macro.
#define     slist_data(node) ((node)->data)

/// Node next macro.
#define     slist_next(node) ((node)->next)

/// Tests node if it head macro.
#define     slist_is_head(list, node) ((node) == slist_head(list) ? 1 : 0)

/// Tests node if it tail macro.
#define     slist_is_tail(node) (slist_next(node) == NULL ? 1 : 0)

#endif // SLIST_H__
