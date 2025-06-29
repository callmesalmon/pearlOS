/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Includes */
#include <stddef.h>

/* Queue structure */
typedef struct {
    void** items;             /* Array of pointers to items */
    unsigned int capacity;    /* Maximum number of items */
    unsigned int size;        /* Current number of items */
    unsigned int head;        /* Index of the head (front) */
    unsigned int tail;        /* Index of the tail (back) */
    unsigned int item_size;   /* Size of each item in bytes */
} Queue;

/* Queue functions */

/**
* Initializes a new queue.
* 
* @param queue The queue to initialize.
* @param item_size The size of each item in bytes.
* @param initial_capacity The initial capacity of the queue.
*/
void queue_init(Queue* queue, unsigned int item_size, unsigned int initial_capacity);

/**
* Destroys the queue and frees allocated memory.
* 
* @param queue The queue to destroy.
*/
void queue_destroy(Queue* queue);

/**
* Adds an item to the back of the queue.
* 
* @param queue The queue to add the item to.
* @param item The item to add (pointer to the item).
* @return true if the item was successfully added, false if there was an error.
*/
bool queue_enqueue(Queue* queue, void* item);

/**
* Removes and returns the item from the front of the queue.
* NOTE: The caller is responsible for freeing the returned memory.
* 
* @param queue The queue to remove the item from.
* @return A pointer to the removed item, or NULL if the queue is empty.
*/
void* queue_dequeue(Queue* queue);

/**
* Removes and frees the item from the front of the queue.
* 
* @param queue The queue to remove the item from.
* @return true if an item was removed, false if the queue was empty.
*/
bool queue_dequeue_free(Queue* queue);

/**
* Peeks at the front item without removing it.
* 
* @param queue The queue to peek at.
* @return A pointer to the front item, or NULL if the queue is empty.
*/
void* queue_peek(const Queue* queue);

/**
* Checks if the queue is empty.
* 
* @param queue The queue to check.
* @return true if the queue is empty, false otherwise.
*/
bool queue_empty(const Queue* queue);

/**
* Returns the current size of the queue.
* 
* @param queue The queue to check.
* @return The current number of items in the queue.
*/
unsigned int queue_size(const Queue* queue);

/**
* Checks if the queue is valid/initialized.
* 
* @param queue The queue to check.
* @return true if the queue is valid, false otherwise.
*/
bool queue_is_valid(const Queue* queue);