#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file array.h
 * @brief A dynamic, mutable array implementation in C.
 *
 * This array stores integer elements in a contiguous heap-allocated buffer
 * and automatically resizes as elements are added or removed.
 *
 * Features:
 *  - O(1) indexed access
 *  - Amortized O(1) insertion at the end
 *  - O(n) insertion and removal at arbitrary positions
 *  - Automatic growth and shrinkage
 *  - Explicit memory management
 *
 * The internal structure of the array is opaque to users.
 *
 * @author Kiril Shishkoski
 * @version 1.0
 * @copyright Copyright (c) 2026 Kiril Shishkoski
 * @license MIT
 */

typedef struct Array Array;



/**
 * @brief Create a new dynamic array.
 *
 * Allocates memory for an array with an initial capacity of at least @p size.
 * The array will grow or shrink automatically as needed.
 *
 * @param size Initial capacity of the array.
 *
 * @return Pointer to a newly created Array, or NULL on allocation failure.
 */
Array * array_create(size_t size);



/**
 * @brief Destroy an array and free its memory.
 *
 * Frees the internal buffer and the array structure itself.
 *
 * @param array Pointer to the array to destroy.
 */
bool array_destroy(Array * array);



/**
 * @brief Append an element to the end of the array.
 *
 * Automatically resizes the array if capacity is exceeded.
 *
 * @param element Value to insert.
 * @param array Pointer to the array.
 */
void array_push(int element, Array * array);



/**
 * @brief Remove the last element from the array.
 *
 * Automatically resizes the array if usage drops below a threshold.
 * Does nothing if the array is empty.
 *
 * @param array Pointer to the array.
 */
void array_pop(Array * array);



/**
 * @brief Insert an element at a specific index.
 *
 * Shifts elements to the right to make room.
 * Automatically resizes the array if needed.
 *
 * @param index Position at which to insert.
 * @param element Value to insert.
 * @param array Pointer to the array.
 */
void array_insert_at(size_t index, int element, Array * array);



/**
 * @brief Remove the element at a specific index.
 *
 * Shifts elements to the left to fill the gap.
 * Automatically resizes the array if usage drops.
 *
 * @param index Index of the element to remove.
 * @param array Pointer to the array.
 */
void array_remove_at(size_t index, Array * array);



/**
 * @brief Retrieve the element at a given index.
 *
 * @param index Index to access.
 * @param array Pointer to the array.
 *
 * @return Element value, or -1 if the index is invalid.
 */
int array_element_at(size_t index, Array * array);



/**
 * @brief Find the index of a given element.
 *
 * Performs a linear search.
 *
 * @param element Element to search for.
 * @param array Pointer to the array.
 *
 * @return Index of the element, or -1 if not found.
 */
int array_index_of(int element, Array * array);



/**
 * @brief Get the number of elements currently stored.
 *
 * @param array Pointer to the array.
 *
 * @return Number of elements in the array.
 */
size_t array_length(Array * array);



/**
 * @brief Reverse the array in place.
 *
 * @param array Pointer to the array.
 */
void array_reverse(Array * array);



/**
 * @brief Get the current capacity of the array.
 *
 * Returns the total number of elements that the array can hold
 * without requiring reallocation. This is the allocated capacity,
 * not the number of elements currently stored.
 *
 * @param array Pointer to the array.
 *
 * @return The capacity of the array, or 0 if @p array is NULL.
 */
size_t array_size(Array * array);



/**
 * @brief Print all elements in the array.
 *
 * Prints elements from index 0 to length - 1.
 *
 * @param array Pointer to the array.
 */
void array_print(Array * array);



#endif /* ARRAY_H */