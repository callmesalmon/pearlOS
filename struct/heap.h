/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* Includes */
#include <stddef.h>

/* Comparison function type */
typedef int (*HeapCompareFunc)(const void*, const void*);

/* Heap structure */
typedef struct {
    void** items;             /* Array of pointers to items */
    unsigned int capacity;    /* Maximum number of items */
    unsigned int size;        /* Current number of items */
    unsigned int item_size;   /* Size of each item in bytes */
    HeapCompareFunc compare;  /* Function to compare items */
} Heap;

/* Helper macros */
#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

/* Heap functions */

/**
* Initializes a new heap.
* 
* @param heap The heap to initialize.
* @param item_size The size of each item in bytes.
* @param initial_capacity The initial capacity of the heap.
* @param compare Function to compare items (should return <0, 0, >0 for max-heap).
*/
void heap_init(Heap* heap, unsigned int item_size, unsigned int initial_capacity, 
            HeapCompareFunc compare);

/**
* Destroys the heap and frees allocated memory.
* 
* @param heap The heap to destroy.
*/
void heap_destroy(Heap* heap);

/**
* Adds an item to the heap (maintains heap property).
* 
* @param heap The heap to add the item to.
* @param item The item to add (pointer to the item).
* @return true if the item was successfully added, false if there was an error.
*/
bool heap_insert(Heap* heap, void* item);

/**
* Removes and returns the root item from the heap (maintains heap property).
* NOTE: The caller is responsible for freeing the returned memory.
* 
* @param heap The heap to remove the item from.
* @return A pointer to the removed item, or NULL if the heap is empty.
*/
void* heap_extract(Heap* heap);

/**
* Removes and frees the root item from the heap.
* 
* @param heap The heap to remove the item from.
* @return true if an item was removed, false if the heap was empty.
*/
bool heap_extract_free(Heap* heap);

/**
* Returns the root item without removing it.
* 
* @param heap The heap to peek at.
* @return A pointer to the root item, or NULL if the heap is empty.
*/
void* heap_peek(const Heap* heap);

/**
* Checks if the heap is empty.
* 
* @param heap The heap to check.
* @return true if the heap is empty, false otherwise.
*/
bool heap_empty(const Heap* heap);

/**
* Returns the current size of the heap.
* 
* @param heap The heap to check.
* @return The current number of items in the heap.
*/
unsigned int heap_size(const Heap* heap);

/**
* Checks if the heap is valid/initialized.
* 
* @param heap The heap to check.
* @return true if the heap is valid, false otherwise.
*/
bool heap_is_valid(const Heap* heap);