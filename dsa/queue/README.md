## Project Information

- **Author:** Kiril Shishkoski
- **Version:** 1.0
- **License:** MIT
- **Copyright:** © 2026 Kiril Shishkoski

---

# Queue (C)

A simple and efficient **array-based queue (FIFO)** implementation in C using
**contiguous heap memory** and a **circular buffer**.

This project demonstrates low-level data structure design,
manual memory management, and constant-time queue operations.

---

## Features

- Array-based **circular buffer**
- Elements stored in **contiguous heap memory**
- **O(1)** enqueue
- **O(1)** dequeue
- Fixed capacity
- Manual bounds checking
- Manual memory management (`malloc` / `free`)
- Front and back index tracking

---

## Design Overview

- The queue is implemented using a dynamically allocated array
- The structure maintains:
  - `size` → total capacity
  - `currentSize` → number of elements currently in the queue
  - `frontIndex` → index of the front element
  - `backIndex` → index where the next element will be inserted
- Indices wrap around using **modulo arithmetic** to form a circular buffer
- Enqueue adds elements at the back
- Dequeue removes elements from the front

---

## Queue Strategy (Circular Buffer)

- **Enqueue:**  
  Insert element at `backIndex`, then advance it using modulo

- **Dequeue:**  
  Remove element from `frontIndex`, then advance it using modulo

This ensures:
- Constant-time operations
- Efficient memory usage
- No shifting of elements

---

## Public API

```c
struct Queue * queue_create(int size);
void queue_destroy(struct Queue * queue);
void queue_enqueue(int element, struct Queue * queue);
int queue_dequeue(struct Queue * queue);
bool queue_is_empty(struct Queue * queue);
bool queue_is_full(struct Queue * queue);
void queue_print(struct Queue * queue);