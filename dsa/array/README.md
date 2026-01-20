## Project Information

- **Author:** Kiril Shishkoski
- **Version:** 1.0
- **License:** MIT
- **Copyright:** © 2026 Kiril Shishkoski

---

# Array (C)

A simple and efficient **dynamic (mutable) array** implementation in C using
**contiguous heap memory** with automatic resizing.

This project demonstrates low-level data structure design,
manual memory management, and performance trade-offs in C.

---

## Features

- Integer elements stored in contiguous memory
- **O(1)** indexed access
- **Amortized O(1)** insertion at the end (push)
- **O(n)** insertion and removal at arbitrary positions
- Automatic **capacity growth and shrink**
- Minimum capacity enforcement
- Manual bounds checking
- Manual memory management (`malloc` / `realloc` / `free`)

---

## Design Overview

- Elements are stored in a dynamically allocated buffer
- The array maintains:
  - `size` → current capacity
  - `head` → number of elements
- Capacity **doubles** when full
- Capacity **halves** when usage drops below 25%, down to a minimum size
- Insert and remove operations shift elements as needed
- Reversal is performed in place
- Memory may be reallocated transparently during resizing

---

## Resizing Strategy

- **Grow:**  
  When `head == size`, capacity is doubled

- **Shrink:**  
  When `head ≤ size / 4` and `size > MIN_SIZE`, capacity is halved

This ensures:
- Efficient memory usage
- Amortized constant-time append
- Avoidance of frequent reallocations

---

## Public API

```c
struct Array * array_create(int size);
bool array_destroy(struct Array * array);
void array_push(int element, struct Array * array);
void array_pop(struct Array * array);
void array_insert_at(size_t index, int element, struct Array * array);
void array_remove_at(size_t index, struct Array * array);
int array_element_at(size_t index, struct Array * array);
int array_index_of(int element, struct Array * array);
size_t array_length(struct Array * array);
void array_reverse(struct Array * array);
size_t array_size(struct Array * array);
void array_print(struct Array * array);