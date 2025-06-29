#include <mem.h>  // for kmalloc, kfree, memcpy
#include <string.h> // for memcmp

void list_init(LinkedList* list, unsigned int item_size) {
    if (!list || item_size == 0) return;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->item_size = item_size;
}

void list_destroy(LinkedList* list) {
    if (!list) return;

    ListNode* current = list->head;
    while (current) {
        ListNode* next = current->next;
        if (current->data) {
            kfree(current->data);
        }
        kfree(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->item_size = 0;
}

bool list_append(LinkedList* list, const void* data) {
    if (!list || !data) return false;

    ListNode* node = (ListNode*)kmalloc(sizeof(ListNode));
    if (!node) return false;

    void* data_copy = kmalloc(list->item_size);
    if (!data_copy) {
        kfree(node);
        return false;
    }

    memcpy(data_copy, data, list->item_size);

    node->data = data_copy;
    node->next = NULL;

    if (!list->head) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
    return true;
}

bool list_remove(LinkedList* list, const void* data) {
    if (!list || !data || !list->head) return false;

    ListNode* current = list->head;
    ListNode* prev = NULL;

    while (current) {
        if (memcmp(current->data, data, list->item_size) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current == list->tail) {
                list->tail = prev;
            }

            kfree(current->data);
            kfree(current);
            list->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

bool list_empty(const LinkedList* list) {
    return !list || list->size == 0;
}

unsigned int list_size(const LinkedList* list) {
    return list ? list->size : 0;
}