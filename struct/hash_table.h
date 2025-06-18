/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Includes */
#include <stdint.h>
#include <stddef.h>

/* Hash table node structure */
typedef struct HashNode {
    uint32_t key;           /* The key for the hash table entry */
    void* value;            /* Pointer to the stored value */
    struct HashNode* next;  /* Pointer to next node in case of collision */
} HashNode;

/* Hash table structure */
typedef struct {
    HashNode** buckets;     /* Array of pointers to bucket heads */
    size_t bucket_count;    /* Number of buckets in the hash table */
    size_t size;           /* Current number of entries in the table */
} HashTable;

/* Hash table functions */

/**
 * Initializes a new hash table.
 * 
 * @param table The hash table to initialize.
 * @param bucket_count The number of buckets to create.
 */
void hash_table_init(HashTable* table, size_t bucket_count);

/**
 * Destroys the hash table and frees allocated memory.
 * 
 * @param table The hash table to destroy.
 */
void hash_table_destroy(HashTable* table);

/**
 * Inserts a key-value pair into the hash table.
 * 
 * @param table The hash table to insert into.
 * @param key The key for the entry.
 * @param value The value to store.
 * @return true if the insertion was successful, false otherwise.
 */
bool hash_table_insert(HashTable* table, uint32_t key, void* value);

/**
 * Retrieves a value from the hash table by key.
 * 
 * @param table The hash table to search.
 * @param key The key to look up.
 * @return A pointer to the stored value, or NULL if not found.
 */
void* hash_table_get(HashTable* table, uint32_t key);

/**
 * Removes a key-value pair from the hash table.
 * 
 * @param table The hash table to modify.
 * @param key The key to remove.
 * @return true if the key was found and removed, false otherwise.
 */
bool hash_table_remove(HashTable* table, uint32_t key);

/**
 * Returns the current size of the hash table.
 * 
 * @param table The hash table to check.
 * @return The current number of entries in the table.
 */
size_t hash_table_size(const HashTable* table);

/**
 * Checks if a key exists in the hash table.
 * 
 * @param table The hash table to check.
 * @param key The key to look for.
 * @return true if the key exists, false otherwise.
 */
bool hash_table_contains(const HashTable* table, uint32_t key);

#endif // HASHTABLE_H