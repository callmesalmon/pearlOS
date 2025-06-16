/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */
 
#pragma once

#include <stddef.h>

/* Node structure */
typedef struct ListNode {
    void* data;
    struct ListNode* next;
} ListNode;

/* Linked list structure */
typedef struct {
    ListNode* head;
    ListNode* tail;
    unsigned int size;
    unsigned int item_size;
} LinkedList;

/**
 * Initialize linked list.
 * 
 * @param list Pointer to LinkedList to initialize
 * @param item_size Size of data stored in each node (bytes)
 */
void list_init(LinkedList* list, unsigned int item_size);

/**
 * Destroy list, free all nodes and their data.
 * 
 * @param list Pointer to LinkedList to destroy
 */
void list_destroy(LinkedList* list);

/**
 * Insert data at the end of the list.
 * 
 * @param list Pointer to LinkedList
 * @param data Pointer to data to insert
 * @return true if success, false if memory allocation failed
 */
bool list_append(LinkedList* list, const void* data);

/**
 * Remove the first node with data matching `data` (using memcmp).
 * 
 * @param list Pointer to LinkedList
 * @param data Pointer to data to remove
 * @return true if removed, false if not found
 */
bool list_remove(LinkedList* list, const void* data);

/**
 * Check if the list is empty.
 * 
 * @param list Pointer to LinkedList
 * @return true if empty, false otherwise
 */
bool list_empty(const LinkedList* list);

/**
 * Get the size of the list.
 * 
 * @param list Pointer to LinkedList
 * @return number of elements
 */
unsigned int list_size(const LinkedList* list);
