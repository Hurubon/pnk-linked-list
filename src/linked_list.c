#include <pnk/linked_list.h>

/********************************* Internal *********************************/
static inline bool
is_head(struct pnk_list_elem* e)
{
    return e != NULL && e->prev == NULL;
}

static inline bool
is_tail(struct pnk_list_elem* e)
{
    return e != NULL && e->next == NULL;
}

static inline bool
is_inner(struct pnk_list_elem* e)
{
    return e != NULL && !is_head(e) && !is_tail(e);
}

/*********************************** Init ***********************************/
void
pnk_list_init(struct pnk_list* list)
{
    *list = (struct pnk_list)
    {
        .sentinel_head = (struct pnk_list_elem) { .prev = NULL },
        .sentinel_tail = (struct pnk_list_elem) { .next = NULL }
    };
    list->sentinel_head.next = &list->sentinel_tail;
    list->sentinel_tail.prev = &list->sentinel_head;
}

/********************************* Iterator *********************************/
struct pnk_list_elem*
pnk_list_begin(struct pnk_list* list)
{
    return list->sentinel_head.next;
}

struct pnk_list_elem*
pnk_list_rbegin(struct pnk_list* list)
{
    return list->sentinel_tail.prev;
}

struct pnk_list_elem*
pnk_list_end(struct pnk_list* list)
{
    return &list->sentinel_tail;
}

struct pnk_list_elem*
pnk_list_rend(struct pnk_list* list)
{
    return &list->sentinel_head;
}

struct pnk_list_elem*
pnk_list_prev(struct pnk_list_elem* element)
{
    return element->prev;
}

struct pnk_list_elem*
pnk_list_next(struct pnk_list_elem* element)
{
    return element->next;
}
/**************************** Adding to the list ****************************/
void
pnk_list_insert(struct pnk_list_elem* before,
                struct pnk_list_elem* element)
{
    element->prev = before->prev;
    element->next = before;
    element->prev->next = element;
    before->prev = element;
}

void
pnk_list_push_front(struct pnk_list*      list,
                    struct pnk_list_elem* element)
{
    return pnk_list_insert(pnk_list_begin(list), element);
}

void
pnk_list_push_back(struct pnk_list*      list,
                   struct pnk_list_elem* element)
{
    return pnk_list_insert(pnk_list_end(list), element);
}

/************************** Removing from the list **************************/
struct pnk_list_elem*
pnk_list_short_circuit(struct pnk_list_elem* element)
{
    element->prev->next = element->next;
    element->next->prev = element->prev;
    return element->next;
}

struct pnk_list_elem*
pnk_list_pop_front(struct pnk_list* list)
{
    void* const front = list->sentinel_head.next;
    (void) pnk_list_short_circuit(front);
    return front;
}

struct pnk_list_elem*
pnk_list_pop_back(struct pnk_list* list)
{
    void* const back = list->sentinel_tail.prev;
    (void) pnk_list_short_circuit(back);
    return back;
}

/******************************* Info queries *******************************/
size_t
pnk_list_size(struct pnk_list* list)
{
    size_t size = 0;
    pnk_list_for(iter, list)
        size += 1;
    return size;
}

bool
pnk_list_is_empty(struct pnk_list* list)
{
    return pnk_list_begin(list) == pnk_list_end(list);
}
