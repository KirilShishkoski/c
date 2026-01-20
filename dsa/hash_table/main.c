#include <stdio.h>
#include "hash_table.h"

int main(void) {
    /* Create a hash table with 16 buckets and load factor 0.75 */
    HashTable *ht = hash_table_create(16, 0.75f);
    if (ht == NULL) {
        fprintf(stderr, "Failed to create hash table\n");
        return 1;
    }

    /* Insert some key-value pairs */
    hash_table_put(1, 100, ht);
    hash_table_put(2, 200, ht);
    hash_table_put(42, 4200, ht);
    hash_table_put(1, 111, ht);  // update existing key

    /* Retrieve values */
    int *value;

    value = hash_table_get(1, ht);
    if (value)
        printf("Key 1 -> %d\n", *value);
    else
        printf("Key 1 not found\n");

    value = hash_table_get(2, ht);
    if (value)
        printf("Key 2 -> %d\n", *value);
    else
        printf("Key 2 not found\n");

    value = hash_table_get(42, ht);
    if (value)
        printf("Key 42 -> %d\n", *value);
    else
        printf("Key 42 not found\n");

    value = hash_table_get(99, ht);
    if (value)
        printf("Key 99 -> %d\n", *value);
    else
        printf("Key 99 not found\n");

    /* Print size */
    printf("Hash table size: %zu\n", hash_table_size(ht));

    /* Destroy hash table */
    if (!hash_table_destroy(ht)) {
        fprintf(stderr, "Failed to destroy hash table\n");
        return 1;
    }

    return 0;
}