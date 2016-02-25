#ifndef DLIST_H__
#define DLIST_H__

#include <stddef.h>
#include "Utils.h"

/// Double linked list node.
struct DListNode_
{
    /// Pointer to next node,
    /// NULL if there is no next node.
    struct DListNode_ *next;

    /// Pointer to previous node,
    /// NULL if there is no previous node.
    struct DListNode_ *prev;

    /// Pointer to data.
    void              *data;
};

typedef struct DListNode_ DListNode;

/// Double linked list.
struct DList_
{
    /// Number of nodes.
    size_t           size;

    /// Function for testing equality of data.
    eq_func          match;

    /// Function for destroying data when
    /// deleting list.
    destructor_func  destroy;

    /// Pointer to head node.
    DListNode       *head;

    /// Pointer to tail node.
    DListNode       *tail;
};

typedef struct DList_ DList;

/// Initializes DList structure.
extern void dlist_init(DList *list, destructor_func destructor);

/// Destroys list with all it's data.
extern void dlist_destroy(DList *list);

/// Inserts new node after existing node.
/// Returns 0 if success or 1 on fail.
extern int  dlist_insert_after(DList *list, DListNode *node, void *data);

/// Inserts new node before existing node.
/// Returns 0 if success or 1 on fail.
extern int  dlist_insert_before(DList *list, DListNode *node, void *data);

/// Removes node from the list.
/// Returns 0 if success or 1 on fail.
extern int  dlist_remove(DList *list, DListNode *node, void **data);

/// List size macro.
#define     dlist_size(list) ((list)->size)

/// List head macro.
#define     dlist_head(list) ((list)->head)

/// List tail macro.
#define     dlist_tail(list) ((list)->tail)

/// Node next macro.
#define     dlist_next(node) ((node)->next)

/// Node previous macro.
#define     dlist_prev(node) ((node)->prev)

/// Node data macro.
#define     dlist_data(node) ((node)->data)

/// Tests node if it head macro.
#define     dlist_is_head(node) (dlist_prev(node) == NULL ? 1 : 0)

/// Tests node if it tail macro.
#define     dlist_is_tail(node) (dlist_next(node) == NULL ? 1 : 0)

#endif // DLIST_H__
