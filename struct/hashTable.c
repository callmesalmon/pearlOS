/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include "hashTable.h"
#include <mem.h>      // for kmalloc, kfree
#include <string.h>   // for memcpy
#include <printk.h>   // for error logging if available

// Simple hash function using FNV-1a
static inline uint64_t hash(uint64_t key, size_t bucket_count) {
    const uint64_t FNV_PRIME = 0x100000001b3;
    const uint64_t FNV_OFFSET = 0xcbf29ce484222325;

    uint64_t hash = FNV_OFFSET;
    for (int i = 0; i < 8; i++) {
        hash ^= (key >> (i * 8)) & 0xFF;
        hash *= FNV_PRIME;
    }

    return hash % bucket_count;
}

void hash_table_init(HashTable* table, size_t bucket_count) {
    if (!table || bucket_count == 0) return;

    table->buckets = (HashNode**)kmalloc(bucket_count * sizeof(HashNode*));
    if (!table->buckets) return;

    for (size_t i = 0; i < bucket_count; i++) {
        table->buckets[i] = NULL;
    }

    table->bucket_count = bucket_count;
    table->size = 0;
}

void hash_table_destroy(HashTable* table) {
    if (!table) return;

    for (size_t i = 0; i < table->bucket_count; i++) {
        HashNode* current = table->buckets[i];
        while (current) {
            HashNode* next = current->next;
            if (current->value) {
                kfree(current->value);
            }
            kfree(current);
            current = next;
        }
    }

    kfree(table->buckets);
    table->buckets = NULL;
    table->bucket_count = 0;
    table->size = 0;
}

bool hash_table_insert(HashTable* table, uint64_t key, void* value) {
    if (!table || !value) return false;

    size_t index = hash(key, table->bucket_count);
    HashNode* new_node = (HashNode*)kmalloc(sizeof(HashNode));
    if (!new_node) {
        printk("hash_table_insert: kmalloc failed for new node\n");
        return false;
    }

    new_node->key = key;
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    table->size++;

    return true;
}

void* hash_table_get(HashTable* table, uint64_t key) {
    if (!table) return NULL;

    size_t index = hash(key, table->bucket_count);
    HashNode* current = table->buckets[index];

    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

bool hash_table_remove(HashTable* table, uint64_t key) {
    if (!table) return false;

    size_t index = hash(key, table->bucket_count);
    HashNode* current = table->buckets[index];
    HashNode* prev = NULL;

    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }

            if (current->value) {
                kfree(current->value);
            }
            kfree(current);
            table->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

size_t hash_table_size(const HashTable* table) {
    return table ? table->size : 0;
}

bool hash_table_contains(const HashTable* table, uint64_t key) {
    if (!table) return false;

    size_t index = hash(key, table->bucket_count);
    HashNode* current = table->buckets[index];

    while (current) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }

    return false;
}