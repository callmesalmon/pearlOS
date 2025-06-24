#include <queue.h>
#include <mem.h>
#include <kernel/kmsg.h>

/* Initialize a new queue */
void queue_init(Queue* queue, unsigned int item_size, unsigned int initial_capacity) {
    if (!queue || item_size == 0 || initial_capacity == 0) {
        return;
    }
    
    queue->items = kmalloc(initial_capacity * sizeof(void*));
    if (!queue->items) {
        queue->capacity = 0;
        queue->size = 0;
        queue->head = 0;
        queue->tail = 0;
        queue->item_size = 0;
        return;
    }
    
    queue->capacity = initial_capacity;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->item_size = item_size;
}

/* Destroy a queue and free its memory */
void queue_destroy(Queue* queue) {
    if (!queue || !queue->items) {
        return;
    }
    
    // Free each item that was allocated by the queue
    for (unsigned int i = 0; i < queue->size; i++) {
        unsigned int index = (queue->head + i) % queue->capacity;
        if (queue->items[index]) {
            kfree(queue->items[index]);
        }
    }
    
    kfree(queue->items);
    queue->items = NULL;
    queue->capacity = 0;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->item_size = 0;
}

/* Add an item to the back of the queue */
bool queue_enqueue(Queue* queue, void* item) {
    if (!queue || !item || !queue->items) {
        return false;
    }
    
    /* Resize if needed */
    if (queue->size >= queue->capacity) {
        unsigned int new_capacity = queue->capacity * 2;
        void** new_items = kmalloc(new_capacity * sizeof(void*));
        
        if (!new_items) {
            return false; // Failed to allocate memory
        }
        
        /* Copy existing items in order */
        for (unsigned int i = 0; i < queue->size; i++) {
            unsigned int index = (queue->head + i) % queue->capacity;
            new_items[i] = queue->items[index];
        }
        
        /* Free old memory and update */
        kfree(queue->items);
        queue->items = new_items;
        queue->capacity = new_capacity;
        queue->head = 0;
        queue->tail = queue->size;
    }
    
    /* Allocate memory for the item and copy the content */
    void* new_item = kmalloc(queue->item_size);
    if (!new_item) {
        return false; // Failed to allocate memory
    }
    
    memcpy(new_item, item, queue->item_size);
    queue->items[queue->tail] = new_item;
    
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;
    
    return true;
}

/* Remove and return the item from the front of the queue */
void* queue_dequeue(Queue* queue) {
    if (!queue || queue_empty(queue)) {
        return NULL;
    }
    
    void* item = queue->items[queue->head];
    queue->items[queue->head] = NULL; // Clear the pointer
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    
    return item; // Caller is responsible for freeing this memory
}

/* Peek at the front item without removing it */
void* queue_peek(const Queue* queue) {
    if (!queue || queue_empty(queue)) {
        return NULL;
    }
    
    return queue->items[queue->head];
}

/* Remove and free the item from the front of the queue */
bool queue_dequeue_free(Queue* queue) {
    if (!queue || queue_empty(queue)) {
        return false;
    }
    
    void* item = queue->items[queue->head];
    if (item) {
        kfree(item);
    }
    
    queue->items[queue->head] = NULL;
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    
    return true;
}

/* Check if the queue is empty */
bool queue_empty(const Queue* queue) {
    return !queue || queue->size == 0;
}

/* Get the current size of the queue */
unsigned int queue_size(const Queue* queue) {
    return queue ? queue->size : 0;
}

/* Check if queue is valid/initialized */
bool queue_is_valid(const Queue* queue) {
    return queue && queue->items && queue->capacity > 0;
}