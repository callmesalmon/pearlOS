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

/* Stack structure */
typedef struct {
    void** items;     /* Array of pointers to items */
    unsigned int capacity;    /* Maximum number of items */
    unsigned int size;        /* Current number of items */
    unsigned int item_size;   /* Size of each item in bytes */
} Stack;

/* Stack functions */

/**
* Initializes a new stack.
* 
* @param stack The stack to initialize.
* @param item_size The size of each item in bytes.
* @param initial_capacity The initial capacity of the stack.
*/
void stack_init(Stack* stack, unsigned int item_size, unsigned int initial_capacity);

/**
* Destroys the stack and frees allocated memory.
* 
* @param stack The stack to destroy.
*/
void stack_destroy(Stack* stack);

/**
* Pushes an item onto the stack.
* 
* @param stack The stack to push the item onto.
* @param item The item to push (pointer to the item).
* @return true if the item was successfully pushed, false if there was an error.
*/
bool stack_push(Stack* stack, void* item);

/**
* Pops the top item from the stack.
* 
* @param stack The stack to pop the item from.
* @return A pointer to the popped item, or NULL if the stack is empty.
*/
void* stack_pop(Stack* stack);

/**
* Checks if the stack is empty.
* 
* @param stack The stack to check.
* @return true if the stack is empty, false otherwise.
*/
bool stack_empty(const Stack* stack);

/**
* Returns the current size of the stack.
* 
* @param stack The stack to check.
* @return The current number of items in the stack.
*/
unsigned int stack_size(const Stack* stack);