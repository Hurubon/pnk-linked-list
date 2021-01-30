#include <stdio.h>
#include <stdlib.h>
#include <pnk/linked_list.h>

struct test
{
    struct pnk_list_elem elem;
    int dummy;
};

int main(void)
{
    struct pnk_list list;
    pnk_list_init(&list);

    for (int i = 0; i < 10; ++i)
    {
        struct test* t = malloc(sizeof *t);
        t->dummy = i;
        if (i % 2 == 0)
            pnk_list_push_front(&list, &t->elem);
        else
            pnk_list_push_back(&list, &t->elem);
    }

    pnk_list_for(i, &list)
    {
        struct test* e = pnk_list_entry(i, struct test, elem);
        printf("%d ", e->dummy);
    }

    puts("");

    while (!pnk_list_is_empty(&list))
    {
        struct pnk_list_elem* e = pnk_list_pop_front(&list);
        struct test* t = pnk_list_entry(e, struct test, elem);
        printf("%d ", t->dummy);
        free(t);
    }

}