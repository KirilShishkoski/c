## Project Information

- **Author:** Kiril Shishkoski
- **Version:** 1.0
- **License:** MIT
- **Copyright:** © 2026 Kiril Shishkoski

---

# Doubly Linked List (C)

A clean and efficient **doubly linked list** implementation in C with
explicit memory management and a well-defined public API.

This project demonstrates classic data structure design,
pointer manipulation, and safe heap memory handling in C.

---

## Features

- Integer elements stored in dynamically allocated nodes
- Bidirectional traversal (`prev` / `next`)
- **O(1)** insertion at head and tail
- **O(1)** removal at head and tail
- **O(1)** insertion and removal after a known node
- Maintains both `head` and `tail` pointers
- Tracks list size explicitly
- Fully manual memory management (`malloc` / `free`)
- Opaque data structures for encapsulation

---

## Design Overview

- Each element is stored in a dynamically allocated node
- Every node maintains:
  - a pointer to the previous node
  - a pointer to the next node
- The list maintains:
  - `head` → first node
  - `tail` → last node
  - `size` → number of elements
- Insertions and removals update both forward and backward links
- The internal structure is hidden from users via opaque types

---

## Time Complexity

| Operation              | Complexity |
|-----------------------|------------|
| Insert at head         | O(1)       |
| Insert at tail         | O(1)       |
| Insert after node      | O(1)       |
| Remove head            | O(1)       |
| Remove tail            | O(1)       |
| Remove after node      | O(1)       |
| Traverse               | O(n)       |
| Length                 | O(1)       |

---

## Memory Management

- Nodes are allocated individually on the heap
- The list structure owns all nodes
- `dll_destroy()`:
  - Frees every node
  - Frees the list structure itself
- Users should **not** manually free nodes once inserted into the list
- Pointer invalidation after destruction is recommended

---

## Public API

```c
DoublyLinkedList * dll_create(void);
bool dll_destroy(DoublyLinkedList * dll);
Node * dll_node_create(int value);
void dll_insert_head(Node * node, DoublyLinkedList * dll);
void dll_insert_tail(Node * node, DoublyLinkedList * dll);
void dll_insert_after(Node * nodeAfter, Node * newNode, DoublyLinkedList * dll);
void dll_remove_head(DoublyLinkedList * dll);
void dll_remove_tail(DoublyLinkedList * dll);
void dll_remove_after(Node * nodeAfter, DoublyLinkedList * dll);
void dll_traverse(const DoublyLinkedList * dll);
size_t dll_length(const DoublyLinkedList * dll);