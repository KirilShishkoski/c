# Data Structures & Algorithms (C)

## Project Information

- **Author:** Kiril Shishkoski  
- **Language:** C (C11)  
- **License:** MIT  
- **Copyright:** © 2026 Kiril Shishkoski  

---

## Overview

This directory contains a collection of **fundamental data structures**
implemented from scratch in **C**, with a focus on:

- Correctness and safety
- Explicit memory management
- Clean API design
- Time and space complexity awareness

The goal of this project is **educational and demonstrative**:
to showcase low-level programming skills, understanding of core data
structures, and familiarity with idiomatic C development practices.

Each data structure is implemented as a **self-contained module**
with its own source files, documentation, and build instructions.

---

## Implemented Data Structures

| Data Structure | Description |
|---------------|-------------|
| Array         | Basic dynamic array implementation |
| Linked List | Singly and doubly linked list implementation | 
| Stack         | LIFO structure with push/pop operations |
| Queue         | FIFO structure |
| Hash Table      | Hash table using separate chaining and dynamic resizing |


More data structures may be added over time.

---

## Directory Structure

```text
dsa/
├── array/
│   ├── array.h
│   ├── array.c
│   ├── main.c
│   ├── Makefile
│   └── README.md
│
├── linked_list/
│   ├── singly
│   │   ├── singly_linked_list.h
│   │   ├── singly_linked_list.c
│   │   ├── main.c
│   │   ├── Makefile
│   │   └── README.md
│   │
│   └── doubly
│       ├── doubly_linked_list.h
│       ├── doubly_linked_list.c
│       ├── main.c
│       ├── Makefile
│       └── README.md
│
├── stack/
│   ├── stack.h
│   ├── stack.c
│   ├── main.c
│   ├── Makefile
│   └── README.md
│
├── queue/
│   ├── queue.h
│   ├── queue.c
│   ├── main.c
│   ├── Makefile
│   └── README.md
│
├── hash_table/
│   ├── hash_table.h
│   ├── hash_table.c
│   ├── main.c
│   ├── Makefile
│   └── README.md
│
└── README.md
```
