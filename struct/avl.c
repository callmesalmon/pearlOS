/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */


#include "avl.h"
#include <mem.h> 

#ifndef NULL
#define NULL ((void*)0)
#endif

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int height(AVLNode* node) {
    return node ? node->height : 0;
}

static AVLNode* create_node(uint32_t key, void* value) {
    AVLNode* node = (AVLNode*)kmalloc(sizeof(AVLNode));
    if (!node) return NULL;

    node->key = key;
    node->value = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

static AVLNode* right_rotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

static AVLNode* left_rotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

static int get_balance(AVLNode* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

static void free_node(AVLNode* node) {
    if (!node) return;
    if (node->value) kfree(node->value);
    kfree(node);
}

static void avl_node_destroy(AVLNode* node) {
    if (!node) return;
    avl_node_destroy(node->left);
    avl_node_destroy(node->right);
    free_node(node);
}

void avl_init(AVLTree* tree) {
    if (!tree) return;
    tree->root = NULL;
    tree->size = 0;
}

void avl_destroy(AVLTree* tree) {
    if (!tree) return;
    avl_node_destroy(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

static AVLNode* avl_insert_node(AVLNode* node, uint32_t key, void* value, bool* inserted) {
    if (!node) {
        *inserted = true;
        return create_node(key, value);
    }

    if (key < node->key) {
        node->left = avl_insert_node(node->left, key, value, inserted);
    } else if (key > node->key) {
        node->right = avl_insert_node(node->right, key, value, inserted);
    } else {
        // Duplicate keys not allowed
        *inserted = false;
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

bool avl_insert(AVLTree* tree, uint32_t key, void* value) {
    if (!tree || !value) return false;
    bool inserted = false;
    tree->root = avl_insert_node(tree->root, key, value, &inserted);
    if (inserted) tree->size++;
    return inserted;
}

static AVLNode* min_value_node(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

static AVLNode* avl_remove_node(AVLNode* root, uint32_t key, bool* removed) {
    if (!root) return NULL;

    if (key < root->key) {
        root->left = avl_remove_node(root->left, key, removed);
    } else if (key > root->key) {
        root->right = avl_remove_node(root->right, key, removed);
    } else {
        *removed = true;

        // Node with one or no child
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                // No child case
                free_node(root);
                return NULL;
            } else {
                // One child case
                if (root->value) kfree(root->value);
                *root = *temp;
                kfree(temp);
                return root;
            }
        } else {
            // Node with two children
            AVLNode* temp = min_value_node(root->right);
            root->key = temp->key;

            if (root->value) kfree(root->value);
            root->value = temp->value;

            // Remove the inorder successor, but avoid double free of value
            bool dummy = false;
            root->right = avl_remove_node(root->right, temp->key, &dummy);
        }
    }

    if (!root) return NULL;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

bool avl_remove(AVLTree* tree, uint32_t key) {
    if (!tree) return false;
    bool removed = false;
    tree->root = avl_remove_node(tree->root, key, &removed);
    if (removed) tree->size--;
    return removed;
}

void* avl_get(const AVLTree* tree, uint32_t key) {
    if (!tree) return NULL;
    AVLNode* current = tree->root;
    while (current) {
        if (key == current->key) return current->value;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return NULL;
}

size_t avl_size(const AVLTree* tree) {
    return tree ? tree->size : 0;
}

bool avl_contains(const AVLTree* tree, uint32_t key) {
    return avl_get(tree, key) != NULL;
}