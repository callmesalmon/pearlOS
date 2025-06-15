/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#include <heap.h>
#include <mem.h>
#include <kernel/kmsg.h>

/* Helper function to swap two items in the heap */
static void heap_swap(Heap* heap, unsigned int i, unsigned int j) {
    void* temp = heap->items[i];
    heap->items[i] = heap->items[j];
    heap->items[j] = temp;
}

/* Helper function to maintain heap property by bubbling up */
static void heap_bubble_up(Heap* heap, unsigned int i) {
    while (i > 0) {
        unsigned int parent = PARENT(i);
        if (heap->compare(heap->items[i], heap->items[parent]) > 0) {
            heap_swap(heap, i, parent);
            i = parent;
        } else {
            break;
        }
    }
}

/* Helper function to maintain heap property by bubbling down */
static void heap_bubble_down(Heap* heap, unsigned int i) {
    while (true) {
        unsigned int left = LEFT(i);
        unsigned int right = RIGHT(i);
        unsigned int largest = i;

        if (left < heap->size && 
            heap->compare(heap->items[left], heap->items[largest]) > 0) {
            largest = left;
        }

        if (right < heap->size && 
            heap->compare(heap->items[right], heap->items[largest]) > 0) {
            largest = right;
        }

        if (largest != i) {
            heap_swap(heap, i, largest);
            i = largest;
        } else {
            break;
        }
    }
}

/* Initialize a new heap */
void heap_init(Heap* heap, unsigned int item_size, unsigned int initial_capacity, 
            HeapCompareFunc compare) {
    if (!heap || !compare || item_size == 0 || initial_capacity == 0) {
        return;
    }
    
    heap->items = kmalloc(initial_capacity * sizeof(void*));
    if (!heap->items) {
        heap->capacity = 0;
        heap->size = 0;
        heap->item_size = 0;
        heap->compare = NULL;
        return;
    }
    
    heap->capacity = initial_capacity;
    heap->size = 0;
    heap->item_size = item_size;
    heap->compare = compare;
}

/* Destroy a heap and free its memory */
void heap_destroy(Heap* heap) {
    if (!heap || !heap->items) {
        return;
    }
    
    // Free each item that was allocated by the heap
    for (unsigned int i = 0; i < heap->size; i++) {
        if (heap->items[i]) {
            kfree(heap->items[i]);
        }
    }
    
    kfree(heap->items);
    heap->items = NULL;
    heap->capacity = 0;
    heap->size = 0;
    heap->item_size = 0;
    heap->compare = NULL;
}

/* Add an item to the heap */
bool heap_insert(Heap* heap, void* item) {
    if (!heap || !item || !heap->items || !heap->compare) {
        return false;
    }
    
    // Resize if needed
    if (heap->size >= heap->capacity) {
        unsigned int new_capacity = heap->capacity * 2;
        void** new_items = kmalloc(new_capacity * sizeof(void*));
        
        if (!new_items) {
            return false;
        }
        
        // Copy existing items
        for (unsigned int i = 0; i < heap->size; i++) {
            new_items[i] = heap->items[i];
        }
        
        // Free old memory and update
        kfree(heap->items);
        heap->items = new_items;
        heap->capacity = new_capacity;
    }
    
    // Allocate memory for the item and copy the content
    void* new_item = kmalloc(heap->item_size);
    if (!new_item) {
        return false;
    }
    
    memcpy(new_item, item, heap->item_size);
    heap->items[heap->size] = new_item;
    heap_bubble_up(heap, heap->size);
    heap->size++;
    
    return true;
}

/* Remove and return the root item from the heap */
void* heap_extract(Heap* heap) {
    if (!heap || heap_empty(heap)) {
        return NULL;
    }
    
    void* root = heap->items[0];
    heap->size--;
    
    if (heap->size > 0) {
        heap->items[0] = heap->items[heap->size];
        heap->items[heap->size] = NULL;
        heap_bubble_down(heap, 0);
    } else {
        heap->items[0] = NULL;
    }
    
    return root; // Caller is responsible for freeing this memory
}

/* Remove and free the root item from the heap */
bool heap_extract_free(Heap* heap) {
    if (!heap || heap_empty(heap)) {
        return false;
    }
    
    void* root = heap->items[0];
    heap->size--;
    
    if (heap->size > 0) {
        heap->items[0] = heap->items[heap->size];
        heap->items[heap->size] = NULL;
        heap_bubble_down(heap, 0);
    } else {
        heap->items[0] = NULL;
    }
    
    if (root) {
        kfree(root);
    }
    
    return true;
}

/* Peek at the root item without removing it */
void* heap_peek(const Heap* heap) {
    if (!heap || heap_empty(heap)) {
        return NULL;
    }
    return heap->items[0];
}

/* Check if the heap is empty */
bool heap_empty(const Heap* heap) {
    return !heap || heap->size == 0;
}

/* Get the current size of the heap */
unsigned int heap_size(const Heap* heap) {
    return heap ? heap->size : 0;
}

/* Check if heap is valid/initialized */
bool heap_is_valid(const Heap* heap) {
    return heap && heap->items && heap->capacity > 0 && heap->compare != NULL;
}