#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file queue.h
 * @brief A fixed-capacity circular queue (FIFO) implementation in C.
 *
 * This queue stores integer elements in a contiguous buffer and
 * uses a circular indexing strategy to achieve efficient enqueue
 * and dequeue operations.
 *
 * Features:
 *  - O(1) enqueue and dequeue
 *  - Fixed capacity
 *  - Circular buffer implementation
 *  - Explicit memory management
 *
 * The internal structure of the queue is opaque to users.
 *
 * @author Kiril Shishkoski
 * @version 1.0
 * @license MIT
 */

typedef struct Queue Queue;

/**
 * @brief Create a new queue with a fixed capacity.
 *
 * Allocates memory for a queue capable of holding up to @p size elements.
 *
 * @param size Maximum number of elements the queue can hold.
 *
 * @return Pointer to a newly created Queue, or NULL on allocation failure.
 */
Queue * queue_create(size_t size);

/**
 * @brief Destroy a queue and free its memory.
 *
 * Frees the internal buffer and the queue structure itself.
 *
 * @param queue Pointer to the queue to destroy.
 *
 * @return true if the queue was destroyed, false if @p queue was NULL.
 */
bool queue_destroy(Queue * queue);

/**
 * @brief Add an element to the back of the queue.
 *
 * Does nothing if the queue is full.
 *
 * @param element Value to enqueue.
 * @param queue Pointer to the queue.
 */
void queue_enqueue(int element, Queue * queue);

/**
 * @brief Remove and return the front element of the queue.
 *
 * @param queue Pointer to the queue.
 *
 * @return The dequeued value, or -1 if the queue is empty.
 */
int queue_dequeue(Queue * queue);

/**
 * @brief Check whether the queue is empty.
 *
 * @param queue Pointer to the queue.
 *
 * @return true if the queue is empty, false otherwise.
 */
bool queue_is_empty(const Queue * queue);

/**
 * @brief Check whether the queue is full.
 *
 * @param queue Pointer to the queue.
 *
 * @return true if the queue is full, false otherwise.
 */
bool queue_is_full(const Queue * queue);

/**
 * @brief Print all elements currently in the queue.
 *
 * Elements are printed from front to back.
 *
 * @param queue Pointer to the queue.
 */
void queue_print(const Queue * queue);

#endif /* QUEUE_H */