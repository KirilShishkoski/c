#include <stdio.h>
#include "stack_array.h"

int main(void) {

    printf("== Create stack with capacity 5 ==\n");
    Stack *stack = stack_create(5);
    if (!stack) {
        fprintf(stderr, "Failed to create stack\n");
        return 1;
    }

    printf("Empty: %s\n", stack_is_empty(stack) ? "YES" : "NO");
    printf("Full : %s\n\n", stack_is_full(stack) ? "YES" : "NO");

    printf("== Push elements ==\n");
    stack_push(10, stack);
    stack_push(20, stack);
    stack_push(30, stack);
    stack_push(40, stack);
    stack_push(50, stack);

    printStack(stack);

    printf("Empty: %s\n", stack_is_empty(stack) ? "YES" : "NO");
    printf("Full : %s\n\n", stack_is_full(stack) ? "YES" : "NO");

    printf("== Peek top element ==\n");
    printf("Top element: %d\n\n", stack_peek(stack));

    printf("== Pop two elements ==\n");
    stack_pop(stack);
    stack_pop(stack);

    printStack(stack);

    printf("Empty: %s\n", stack_is_empty(stack) ? "YES" : "NO");
    printf("Full : %s\n\n", stack_is_full(stack) ? "YES" : "NO");

    printf("== Pop remaining elements ==\n");
    while (!stack_is_empty(stack)) {
        printf("Popped: %d\n", stack_peek(stack));
        stack_pop(stack);
    }

    printStack(stack);

    printf("Empty: %s\n", stack_is_empty(stack) ? "YES" : "NO");
    printf("Full : %s\n\n", stack_is_full(stack) ? "YES" : "NO");

    /* Clean up */
    if (stack_destroy(stack)) {
        stack = NULL;
    }

    return 0;
}