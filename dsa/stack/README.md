## Project Information

- **Author:** Kiril Shishkoski
- **Version:** 1.0
- **License:** MIT
- **Copyright:** © 2026 Kiril Shishkoski

---

# Stack (C)

A simple and efficient **array-based stack (LIFO)** implementation in C using
**contiguous heap memory**.

This project demonstrates low-level data structure design,
manual memory management, and constant-time stack operations.

---

## Features

- Array-based stack
- Elements stored in **contiguous heap memory**
- **O(1)** push
- **O(1)** pop
- **O(1)** peek
- Fixed capacity
- Manual bounds checking
- Manual memory management (`malloc` / `free`)
- Top index tracking

---

## Design Overview

- The stack is implemented using a dynamically allocated array
- The structure maintains:
  - `size` → total capacity
  - `topIndex` → index of the next free slot (top of the stack)
- Elements are added and removed only from the top
- Push adds elements to the top
- Pop removes the most recently added element

---

## Stack Strategy (LIFO)

- **Push:**  
  Insert element at `topIndex`, then increment it

- **Pop:**  
  Decrement `topIndex`, effectively removing the top element

This ensures:
- Constant-time operations
- Efficient memory usage
- No shifting of elements

---

## Public API

```c
Stack * stack_create(size_t size);
bool stack_destroy(Stack * stack);
void stack_push(int element, Stack * stack);
void stack_pop(Stack * stack);
int stack_peek(const Stack * stack);
bool stack_is_empty(const Stack * stack);
bool stack_is_full(const Stack * stack);
void printStack(const Stack * stack);