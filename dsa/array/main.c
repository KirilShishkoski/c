#include <stdio.h>
#include "array.h"

int main(void) {
    /* Create a dynamic array with initial capacity */
    Array *array = array_create(4);
    if (!array) {
        fprintf(stderr, "Failed to create array\n");
        return 1;
    }

    printf("== Push elements ==\n");
    array_push(10, array);
    array_push(20, array);
    array_push(30, array);
    array_push(40, array);

    array_print(array);
    printf("Length: %zu\n", array_length(array));
    printf("Capacity: %zu\n\n", array_size(array));

    printf("== Insert at index ==\n");
    array_insert_at(1, 99, array);   /* insert 99 at index 1 */
    array_print(array);

    printf("Length: %zu\n", array_length(array));
    printf("Capacity: %zu\n\n", array_size(array));

    printf("== Remove at index ==\n");
    array_remove_at(2, array);       /* remove element at index 2 */
    array_print(array);

    printf("Length: %zu\n", array_length(array));
    printf("Capacity: %zu\n\n", array_size(array));

    printf("== Access elements ==\n");
    printf("Element at index 0: %d\n", array_element_at(0, array));
    printf("Index of element 30: %d\n\n", array_index_of(30, array));

    printf("== Pop elements ==\n");
    array_pop(array);
    array_pop(array);
    array_print(array);

    printf("Length: %zu\n", array_length(array));
    printf("Capacity: %zu\n\n", array_size(array));

    printf("== Reverse array ==\n");
    array_reverse(array);
    array_print(array);

    printf("\nFinal length: %zu\n", array_length(array));
    printf("Final capacity: %zu\n", array_size(array));

    /* Clean up */
    if (array_destroy(array)) array=NULL;

    return 0;
}