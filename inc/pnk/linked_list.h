/* Heavily inspired by PintOS' implementation and C++ concepts. */

#ifndef PNK_LINKED_LIST_H
#define PNK_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

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