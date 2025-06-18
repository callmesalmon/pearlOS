/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <stack.h>
#include <mem.h>
#include <kernel/kmsg.h>

/* Initialize a new stack */
void stack_init(Stack* stack, uint item_size, uint initial_capacity) {
    stack->items = kmalloc(initial_capacity * sizeof(void*));  // Allocate space for the array of pointers
    stack->capacity = initial_capacity;
    stack->size = 0;
    stack->item_size = item_size;
}

/* Destroy a stack and free its memory */
void stack_destroy(Stack* stack) {
    // Free each item in the stack if they were dynamically allocated
    for (uint i = 0; i < stack->size; i++) {
        kfree(stack->items[i]);  // Assuming items were allocated dynamically
    }
    kfree(stack->items);  // Free the array of pointers
    stack->items = NULL;
    stack->capacity = 0;
    stack->size = 0;
    stack->item_size = 0;
}

/* Add an item to the stack */
bool stack_push(Stack* stack, void* item) {
    /* Resize if needed */
    if (stack->size >= stack->capacity) {
        uint new_capacity = stack->capacity * 2;
        void** new_items = kmalloc(new_capacity * sizeof(void*));
        
        /* Copy existing items */
        for (uint i = 0; i < stack->size; i++) {
            new_items[i] = stack->items[i];
        }
        
        /* Free old memory and update */
        kfree(stack->items);
        stack->items = new_items;
        stack->capacity = new_capacity;
    }
    
    /* Allocate memory for the item and copy the content */
    void* new_item = kmalloc(stack->item_size);
    memcpy(new_item, item, stack->item_size);  // Copy the item to allocated memory
    stack->items[stack->size++] = new_item;     // Add the item to the stack

    return true;
}

/* Remove and return the top item from the stack */
void* stack_pop(Stack* stack) {
    if (stack_empty(stack)) {
        return NULL;
    }
    
    void* item = stack->items[--stack->size];
    return item;
}

/* Check if the stack is empty */
bool stack_empty(const Stack* stack) {
    return stack->size == 0;
}

/* Get the current size of the stack */
uint stack_size(const Stack* stack) {
    return stack->size;
}