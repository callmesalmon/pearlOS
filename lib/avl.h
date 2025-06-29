/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <stddef.h>

/* AVL Tree node structure */
typedef struct AVLNode {
    uint32_t key;          
    void* value;            
    struct AVLNode* left;   
    struct AVLNode* right;  
    int height;             
} AVLNode;

/* AVL Tree structure */
typedef struct {
    AVLNode* root;          
    size_t size;           
} AVLTree;

/* AVL Tree functions */

/**
 * Initializes an empty AVL tree.
 * 
 * @param tree Pointer to the AVLTree to initialize.
 */
void avl_init(AVLTree* tree);

/**
 * Destroys the AVL tree, freeing all nodes and values.
 * 
 * @param tree Pointer to the AVLTree to destroy.
 */
void avl_destroy(AVLTree* tree);

/**
 * Inserts a key-value pair into the AVL tree.
 * 
 * @param tree Pointer to the AVLTree.
 * @param key The key to insert.
 * @param value Pointer to the value associated with the key.
 * @return true if insertion succeeded, false if key exists or allocation fails.
 */
bool avl_insert(AVLTree* tree, uint32_t key, void* value);

/**
 * Retrieves the value associated with a key.
 * 
 * @param tree Pointer to the AVLTree.
 * @param key The key to search.
 * @return Pointer to value or NULL if not found.
 */
void* avl_get(const AVLTree* tree, uint32_t key);

/**
 * Removes a node with the given key from the AVL tree.
 * 
 * @param tree Pointer to the AVLTree.
 * @param key The key to remove.
 * @return true if the node was found and removed, false otherwise.
 */
bool avl_remove(AVLTree* tree, uint32_t key);

/**
 * Returns the number of nodes in the AVL tree.
 * 
 * @param tree Pointer to the AVLTree.
 * @return Number of nodes.
 */
size_t avl_size(const AVLTree* tree);

/**
 * Checks if a key exists in the AVL tree.
 * 
 * @param tree Pointer to the AVLTree.
 * @param key The key to check.
 * @return true if the key exists, false otherwise.
 */
bool avl_contains(const AVLTree* tree, uint32_t key);