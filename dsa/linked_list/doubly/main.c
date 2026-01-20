#include <stdio.h>
#include "doubly_linked_list.h"

int main(void) {
    /* Create doubly linked list */
    DoublyLinkedList *dll = dll_create();
    if (!dll) {
        fprintf(stderr, "Failed to create doubly linked list\n");
        return 1;
    }

    printf("== Insert at head ==\n");
    Node *n1 = dll_node_create(10);
    Node *n2 = dll_node_create(20);
    dll_insert_head(n1, dll);
    dll_insert_head(n2, dll);
    dll_traverse(dll);

    printf("\nLength: %zu\n\n", dll_length(dll));

    printf("== Insert at tail ==\n");
    Node *n3 = dll_node_create(30);
    Node *n4 = dll_node_create(40);
    dll_insert_tail(n3, dll);
    dll_insert_tail(n4, dll);
    dll_traverse(dll);

    printf("\nLength: %zu\n\n", dll_length(dll));

    printf("== Insert after a node ==\n");
    Node *n5 = dll_node_create(99);
    dll_insert_after(n3, n5, dll);   /* insert after node with value 30 */
    dll_traverse(dll);

    printf("\nLength: %zu\n\n", dll_length(dll));

    printf("== Remove head ==\n");
    dll_remove_head(dll);
    dll_traverse(dll);

    printf("\nLength: %zu\n\n", dll_length(dll));

    printf("== Remove tail ==\n");
    dll_remove_tail(dll);
    dll_traverse(dll);

    printf("\nLength: %zu\n\n", dll_length(dll));

    printf("== Remove after a node ==\n");
    dll_remove_after(n3, dll);   /* remove node after value 30 */
    dll_traverse(dll);

    printf("\nLength: %zu\n\n", dll_length(dll));

    /* Clean up */
    if (dll_destroy(dll)) dll = NULL;
    

    return 0;
}