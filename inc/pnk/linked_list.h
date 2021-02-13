/* Heavily inspired by PintOS' implementation and C++ concepts. */

#ifndef PNK_LINKED_LIST_H
#define PNK_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

#define pnk_list_entry(PNK_LIST_ELEM, PNK_STRUCT, PNK_MEMBER) (              \
    (PNK_STRUCT*) ( (char*)                                                  \
        &(PNK_LIST_ELEM)->next - offsetof(PNK_STRUCT, PNK_MEMBER.next)       \
    )                                                                        \
)

#define pnk_list_for(PNK_ITER, PNK_LIST)                                     \
for (struct pnk_list_elem* PNK_ITER  = pnk_list_begin(PNK_LIST);             \
                           PNK_ITER != pnk_list_end(PNK_LIST);               \
                           PNK_ITER  = pnk_list_next(PNK_ITER))

struct pnk_list_elem
{
    struct pnk_list_elem* prev;
    struct pnk_list_elem* next;
};

struct pnk_list
{
    struct pnk_list_elem sentinel_head;
    struct pnk_list_elem sentinel_tail;
};

void                  pnk_list_init          (struct pnk_list* list);

struct pnk_list_elem* pnk_list_begin         (struct pnk_list* list);
struct pnk_list_elem* pnk_list_rbegin        (struct pnk_list* list);
struct pnk_list_elem* pnk_list_end           (struct pnk_list* list);
struct pnk_list_elem* pnk_list_rend          (struct pnk_list* list);

struct pnk_list_elem* pnk_list_prev          (struct pnk_list_elem* element);
struct pnk_list_elem* pnk_list_next          (struct pnk_list_elem* element);

void                  pnk_list_insert        (struct pnk_list_elem* before,
                                              struct pnk_list_elem* element);
void                  pnk_list_push_front    (struct pnk_list*      list,
                                              struct pnk_list_elem* element);
void                  pnk_list_push_back     (struct pnk_list*      list,
                                              struct pnk_list_elem* element);

struct pnk_list_elem* pnk_list_short_circuit (struct pnk_list_elem* element);
struct pnk_list_elem* pnk_list_pop_front     (struct pnk_list* list);
struct pnk_list_elem* pnk_list_pop_back      (struct pnk_list* list);

size_t                pnk_list_size          (struct pnk_list* list);
bool                  pnk_list_is_empty      (struct pnk_list* list);

#endif // PNK_LINKED_LIST_H