#include <stdio.h>
#include <pnk/linked_list.h>

int main(void)
{
    struct pnk_list list;
    pnk_list_init(&list);

    printf("Head: %p %p\n", list.sentinel_head.prev, list.sentinel_head.next);
    printf("Tail: %p %p\n", list.sentinel_tail.prev, list.sentinel_tail.next);
    printf("Begin:  %p\n", pnk_list_begin(&list));
    printf("End:    %p\n", pnk_list_end(&list));
    printf("Rbegin: %p\n", pnk_list_rbegin(&list));
    printf("Rend:   %p\n", pnk_list_rend(&list));
}