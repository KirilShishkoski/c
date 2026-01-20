#include <stdio.h>
#include "singly_linked_list.h"

int main(void) {

    SinglyLinkedList *list = sll_create();
    if (!list) {
        fprintf(stderr, "Failed to create singly linked list\n");
        return 1;
    }

    printf("== Insert at head ==\n");
    Node *n1 = sll_node_create(10);
    Node *n2 = sll_node_create(20);
    Node *n3 = sll_node_create(30);

    sll_insert_head(n1, list);
    sll_insert_head(n2, list);
    sll_insert_head(n3, list);

    sll_traverse(list);
    printf("\nLength: %zu\n\n", sll_length(list));

    printf("== Insert at tail ==\n");
    Node *n4 = sll_node_create(40);
    Node *n5 = sll_node_create(50);

    sll_insert_tail(n4, list);
    sll_insert_tail(n5, list);

    sll_traverse(list);
    printf("\nLength: %zu\n\n", sll_length(list));

    printf("== Insert after known node ==\n");
    Node *n6 = sll_node_create(99);
    sll_insert_after(n1, n6, list);   /* insert after node with value 10 */

    sll_traverse(list);
    printf("\nLength: %zu\n\n", sll_length(list));

    printf("== Remove head ==\n");
    sll_remove_head(list);
    sll_traverse(list);
    printf("\nLength: %zu\n\n", sll_length(list));

    printf("== Remove tail ==\n");
    sll_remove_tail(list);
    sll_traverse(list);
    printf("\nLength: %zu\n\n", sll_length(list));

    printf("== Remove after a node ==\n");
    sll_remove_after(n1, list);
    sll_traverse(list);
    printf("\nLength: %zu\n\n", sll_length(list));

    /* Cleanup */
    if (sll_destroy(list)) list = NULL;

    return 0;
}