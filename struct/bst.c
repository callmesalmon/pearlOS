/*
* Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
* If your copy of this program doesn't include the license, it is
* available to read at:
*
*     https://github.com/jamiebuilds/anti-fascist-mit-license
*
*/

#include "bst.h"
#include <mem.h> 

static void bst_node_destroy(BSTNode* node) {
    if (!node) return;
    bst_node_destroy(node->left);
    bst_node_destroy(node->right);
    if (node->value) {
        kfree(node->value);
    }
    kfree(node);
}

void bst_init(BST* tree) {
    if (!tree) return;
    tree->root = NULL;
    tree->size = 0;
}

void bst_destroy(BST* tree) {
    if (!tree) return;
    bst_node_destroy(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

static BSTNode* bst_node_create(uint64_t key, void* value) {
    BSTNode* node = (BSTNode*)kmalloc(sizeof(BSTNode));
    if (!node) return NULL;
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static BSTNode* bst_node_insert(BSTNode* root, uint64_t key, void* value, bool* inserted) {
    if (!root) {
        *inserted = true;
        return bst_node_create(key, value);
    }
    if (key < root->key) {
        root->left = bst_node_insert(root->left, key, value, inserted);
    } else if (key > root->key) {
        root->right = bst_node_insert(root->right, key, value, inserted);
    } else {
        // Duplicate key, do not insert
        *inserted = false;
    }
    return root;
}

bool bst_insert(BST* tree, uint64_t key, void* value) {
    if (!tree || !value) return false;
    bool inserted = false;
    tree->root = bst_node_insert(tree->root, key, value, &inserted);
    if (inserted) tree->size++;
    return inserted;
}

static void* bst_node_get(BSTNode* root, uint64_t key) {
    if (!root) return NULL;
    if (key == root->key) return root->value;
    else if (key < root->key) return bst_node_get(root->left, key);
    else return bst_node_get(root->right, key);
}

void* bst_get(const BST* tree, uint64_t key) {
    if (!tree) return NULL;
    return bst_node_get(tree->root, key);
}

static BSTNode* bst_node_find_min(BSTNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

static BSTNode* bst_node_remove(BSTNode* root, uint64_t key, bool* removed) {
    if (!root) return NULL;

    if (key < root->key) {
        root->left = bst_node_remove(root->left, key, removed);
    } else if (key > root->key) {
        root->right = bst_node_remove(root->right, key, removed);
    } else {
        // Found node to remove
        *removed = true;
        if (!root->left) {
            BSTNode* right = root->right;
            if (root->value) kfree(root->value);
            kfree(root);
            return right;
        } else if (!root->right) {
            BSTNode* left = root->left;
            if (root->value) kfree(root->value);
            kfree(root);
            return left;
        } else {
            // Two children: find inorder successor (min in right subtree)
            BSTNode* min_node = bst_node_find_min(root->right);
            root->key = min_node->key;

            // Free old value and copy new value pointer
            if (root->value) kfree(root->value);
            root->value = min_node->value;

            // Remove the successor node but don't free value again
            bool dummy = false;
            root->right = bst_node_remove(root->right, min_node->key, &dummy);
        }
    }
    return root;
}

bool bst_remove(BST* tree, uint64_t key) {
    if (!tree) return false;
    bool removed = false;
    tree->root = bst_node_remove(tree->root, key, &removed);
    if (removed) tree->size--;
    return removed;
}

size_t bst_size(const BST* tree) {
    return tree ? tree->size : 0;
}

bool bst_contains(const BST* tree, uint64_t key) {
    if (!tree) return false;
    return bst_get(tree, key) != NULL;
}
