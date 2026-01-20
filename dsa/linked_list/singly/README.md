## Project Information

- **Author:** Kiril Shishkoski
- **Version:** 1.0
- **License:** MIT
- **Copyright:** © 2026 Kiril Shishkoski

---

# Singly Linked List (C)

A simple and efficient **singly linked list** implementation in C using
**heap-allocated nodes** and pointer-based linking.

This project demonstrates low-level data structure design,
explicit memory management, and pointer manipulation in C.

---

## Features

- Integer elements stored in dynamically allocated nodes
- **O(1)** insertion at head
- **O(1)** insertion at tail (with tail pointer)
- **O(1)** removal at head
- **O(n)** removal at tail
- **O(n)** traversal
- Explicit memory allocation and deallocation
- Maintains both **head** and **tail** pointers
- Tracks list size internally

---

## Design Overview

- Each element is stored in a `Node` structure containing:
  - `value` → integer data
  - `next` → pointer to the next node
- The list structure maintains:
  - `head` → first node
  - `tail` → last node
  - `size` → number of nodes
- Nodes are allocated individually on the heap
- Insert and remove operations update pointers as needed
- Memory is explicitly freed during destruction

---

## Complexity Summary

| Operation              | Time Complexity |
|------------------------|-----------------|
| Insert at head         | O(1)            |
| Insert at tail         | O(1)            |
| Insert after node      | O(1)            |
| Remove head            | O(1)            |
| Remove tail            | O(n)            |
| Remove after node      | O(1)            |
| Traverse list          | O(n)            |
| Get length             | O(1)            |

---

## Public API

```c
SinglyLinkedList * sll_create(void);
bool sll_destroy(SinglyLinkedList * sll);
Node * sll_node_create(int value);
void sll_insert_head(Node * node, SinglyLinkedList * sll);
void sll_insert_tail(Node * node, SinglyLinkedList * sll);
void sll_insert_after(Node * nodeAfter, Node * newNode, SinglyLinkedList * sll);
void sll_remove_head(SinglyLinkedList * sll);
void sll_remove_tail(SinglyLinkedList * sll);
void sll_remove_after(Node * nodeAfter, SinglyLinkedList * sll);
void sll_traverse(SinglyLinkedList * sll);
size_t sll_length(SinglyLinkedList * sll);