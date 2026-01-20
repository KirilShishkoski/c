#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file stack.h
 * @brief A fixed-capacity array-based stack (LIFO) implementation in C.
 *
 * This stack stores integer elements in a contiguous heap-allocated
 * buffer and follows the Last-In, First-Out (LIFO) principle.
 *
 * Features:
 *  - O(1) push, pop, and peek operations
 *  - Fixed capacity
 *  - Contiguous memory storage
 *  - Explicit memory management
 *
 * The internal structure of the stack is opaque to users.
 *
 * @author Kiril Shishkoski
 * @version 1.0
 * @license MIT
 */

typedef struct Stack Stack;

/**
 * @brief Create a new stack with a fixed capacity.
 *
 * Allocates memory for a stack capable of holding up to @p size elements.
 *
 * @param size Maximum number of elements the stack can hold.
 *
 * @return Pointer to a newly created Stack, or NULL on allocation failure.
 */
Stack * stack_create(size_t size);

/**
 * @brief Destroy a stack and free its memory.
 *
 * Frees the internal buffer and the stack structure itself.
 *
 * @param stack Pointer to the stack to destroy.
 *
 * @return true if the stack was destroyed, false if @p stack was NULL.
 */
bool stack_destroy(Stack * stack);

/**
 * @brief Push an element onto the top of the stack.
 *
 * Does nothing if the stack is full.
 *
 * @param element Value to push.
 * @param stack Pointer to the stack.
 */
void stack_push(int element, Stack * stack);

/**
 * @brief Remove the top element from the stack.
 *
 * Does nothing if the stack is empty.
 *
 * @param stack Pointer to the stack.
 */
void stack_pop(Stack * stack);

/**
 * @brief Get the top element of the stack without removing it.
 *
 * @param stack Pointer to the stack.
 *
 * @return The top value, or -1 if the stack is empty.
 */
int stack_peek(const Stack * stack);

/**
 * @brief Check whether the stack is empty.
 *
 * @param stack Pointer to the stack.
 *
 * @return true if the stack is empty, false otherwise.
 */
bool stack_is_empty(const Stack * stack);

/**
 * @brief Check whether the stack is full.
 *
 * @param stack Pointer to the stack.
 *
 * @return true if the stack is full, false otherwise.
 */
bool stack_is_full(const Stack * stack);

/**
 * @brief Print all elements currently in the stack.
 *
 * Elements are printed from top to bottom.
 *
 * @param stack Pointer to the stack.
 */
void printStack(const Stack * stack);

#endif /* STACK_H */