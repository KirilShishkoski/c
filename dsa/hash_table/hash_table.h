#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @file hash_table.h
 * @brief A simple hash table implementation using separate chaining.
 *
 * This hash table stores integer keys mapped to integer values.
 * Collisions are handled using linked-list chaining.
 *
 * Features:
 *  - Average O(1) insert and lookup
 *  - Automatic resizing based on load factor
 *  - Uses multiplicative hashing (Knuth's constant)
 *
 * The internal structure of the hash table is opaque to users.
 * 
 * 
 * @author Kiril Shishkoski
 * @version 1.0
 * @copyright Copyright (c) 2026 Kiril Shishkoski
 * @license MIT
 * 
 *
 */
typedef struct HashTable HashTable;



/**
 * @brief Create a new hash table.
 *
 * Allocates and initializes a hash table with a given initial capacity
 * and load factor.
 *
 * @param n Initial number of buckets (must be a power of two).
 * @param load_factor Maximum allowed load factor before resizing.
 *
 * @return Pointer to a newly created HashTable, or NULL on allocation failure.
 */
HashTable * hash_table_create(uint32_t n, float load_factor);



/**
 * @brief Destroy a hash table and free all associated memory.
 *
 * Frees all nodes stored in the hash table, the bucket array,
 * and the hash table structure itself.
 *
 * After calling this function, the HashTable pointer must not be used again.
 *
 * @param ht Pointer to the hash table to destroy.
 *
 * @return true if the hash table was destroyed successfully,
 *         false if ht was NULL.
 */
bool hash_table_destroy(HashTable * ht);



/**
 * @brief Insert or update a key-value pair in the hash table.
 *
 * If the key already exists, its value is updated.
 * If the key does not exist, a new entry is inserted.
 *
 * The hash table automatically resizes if inserting this element
 * would exceed the configured load factor.
 *
 * @param ht Pointer to the hash table.
 * @param key Integer key to insert.
 * @param value Integer value associated with the key.
 */
void hash_table_put(int key, int value, HashTable * ht);



/**
 * @brief Retrieve the value associated with a key.
 *
 * Performs a lookup for the given key.
 *
 * @param ht Pointer to the hash table.
 * @param key Key to search for.
 *
 * @return Pointer to the stored value if the key exists,
 *         or NULL if the key is not found.
 *
 * @note The returned pointer refers to internal storage.
 *       It becomes invalid if the hash table is modified or destroyed.
 */
int * hash_table_get(int key, HashTable * ht);



/**
 * @brief Get the number of elements stored in the hash table.
 *
 * @param ht Pointer to the hash table.
 *
 * @return Number of key-value pairs currently stored,
 *         or 0 if ht is NULL.
 */
size_t hash_table_size(HashTable * ht);



#endif /* HASH_TABLE_H */