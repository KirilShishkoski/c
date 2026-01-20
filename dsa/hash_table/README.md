

## Project Information

- **Author:** Kiril Shishkoski
- **Version:** 1.0
- **License:** MIT
- **Copyright** © 2026 Kiril Shishkoski

---

# Hash Table (C)

A simple and efficient hash table implementation in C using
**separate chaining** for collision resolution and **multiplicative hashing**
(Knuth’s constant).

This project is intended as a low-level data structure implementation
demonstrating memory management, API design, and performance considerations
in C.

---

## Features

- Integer keys mapped to integer values
- Average **O(1)** insertion and lookup
- Collision handling via linked-list chaining
- Automatic resizing based on configurable load factor
- Opaque data structure with a clean public API
- Manual memory management (malloc, calloc / free)

---

## Design Overview

- Buckets are stored as an array of linked lists
- Hashing uses multiplicative hashing with a power-of-two table size
- The table resizes when the load factor threshold is exceeded
- Rehashing is performed during resizing

---

## Public API

```c
HashTable * hash_table_create(uint32_t n, float load_factor);
void hash_table_put(HashTable * ht, int key, int value);
int * hash_table_get(HashTable * ht, int key);
size_t hash_table_size(HashTable * ht);
bool hash_table_destroy(HashTable * ht);
```