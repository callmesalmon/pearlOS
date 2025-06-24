#pragma once

/* Includes */
#include <stdint.h>
#include <stddef.h>

/* Binary Search Tree node structure */
typedef struct BSTNode {
    uint32_t key;           /* The key for the BST entry */
    void* value;            /* Pointer to the stored value */
    struct BSTNode* left;   /* Pointer to left child */
    struct BSTNode* right;  /* Pointer to right child */
} BSTNode;

/* Binary Search Tree structure */
typedef struct {
    BSTNode* root;          /* Pointer to the root node */
    size_t size;            /* Current number of nodes in the tree */
} BST;

/* Binary Search Tree functions */

/**
* Initializes a new empty BST.
* 
* @param tree Pointer to the BST structure to initialize.
*/
void bst_init(BST* tree);

/**
* Destroys the BST, freeing all nodes and their associated values.
* 
* @param tree Pointer to the BST to destroy.
*/
void bst_destroy(BST* tree);

/**
* Inserts a key-value pair into the BST.
* 
* @param tree Pointer to the BST.
* @param key The key to insert.
* @param value Pointer to the value to associate with the key.
* @return true if insertion was successful, false if the key already exists or on failure.
*/
bool bst_insert(BST* tree, uint32_t key, void* value);

/**
* Retrieves a value associated with a given key from the BST.
* 
* @param tree Pointer to the BST.
* @param key The key to search for.
* @return Pointer to the stored value, or NULL if the key is not found.
*/
void* bst_get(const BST* tree, uint32_t key);

/**
* Removes a node by key from the BST.
* 
* @param tree Pointer to the BST.
* @param key The key to remove.
* @return true if the key was found and removed, false otherwise.
*/
bool bst_remove(BST* tree, uint32_t key);

/**
* Returns the current number of nodes stored in the BST.
* 
* @param tree Pointer to the BST.
* @return Number of nodes in the BST.
*/
size_t bst_size(const BST* tree);

/**
* Checks if a key exists in the BST.
* 
* @param tree Pointer to the BST.
* @param key The key to look for.
* @return true if the key exists in the BST, false otherwise.
*/
bool bst_contains(const BST* tree, uint32_t key);
