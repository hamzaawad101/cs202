//100 working 
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include "bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */
int BSTree::Depth(const string &key) const {
    BSTNode *current = sentinel->right; // Start from the root
    int depth = 0;

    // Search for the node
    while (current != sentinel) {
        if (current->key == key) {
            // Found the node, return its depth
            return depth;
        } else if (key < current->key) {
            current = current->left; // Go left
        } else {
            current = current->right; // Go right
        }
        depth++; // Increment depth for each level traversed
    }

    // If the node was not found, return -1
    return -1; 
}

int BSTree::Height() const {
    // Ensure sentinel is valid
    if (!sentinel) {
        return -1; // If sentinel is not initialized, return -1
    }

    // Check if the tree is empty
    if (sentinel->right == sentinel) {
        return -1; // Return -1 for an empty tree
    }

    // Call the recursive function starting from the root
    return recursive_find_height(sentinel->right); // Start from the root
}

vector <string> BSTree::Ordered_Keys() const
{
  vector <string> keys;
  make_key_vector(sentinel->right,keys);
  return keys;
}
    
BSTree::BSTree(const BSTree &t) {
    // Initialize the sentinel node
    sentinel = new BSTNode();
    sentinel->left = NULL;
    sentinel->right = NULL;
    sentinel->parent = NULL;
    size = t.size; // Set the size of the new tree

    // If the original tree is empty, set the sentinel's right to nullptr
    if (t.sentinel->right == NULL) {
        sentinel->right = NULL;
    } else {
        // Perform a simple in-order traversal to copy nodes
        vector<string> keys = t.Ordered_Keys();
        vector<void*> vals = t.Ordered_Vals();
        sentinel->right = make_balanced_tree(keys, vals, 0, size);
        sentinel->right->parent = sentinel; // Set the parent of the root
    }
}

BSTree& BSTree::operator=(const BSTree &t) {
    // Self-assignment check
    if (this == &t) {
        return *this;
    }

    // Clear the current tree
    Clear();

    // Update the size
    size = t.size;

    // Initialize sentinel if it's null
    if (!sentinel) {
        sentinel = new BSTNode();
        sentinel->left = NULL;
        sentinel->right = NULL;
        sentinel->parent = NULL;
    }

    // If the source tree is empty, just reset the right pointer
    if (t.sentinel->right == NULL) {
        sentinel->right = NULL;
    } else {
        // Copy the tree from 't'
        sentinel->right = make_balanced_tree(t.Ordered_Keys(), t.Ordered_Vals(), 0, t.size);
        sentinel->right->parent = sentinel; // Set the parent of the root to the sentinel
    }

    return *this;
}

int BSTree::recursive_find_height(const BSTNode *n) const {
    if (n == sentinel) {
        return 0; // Return 0 for a sentinel node (base case)
    }
    
    // Calculate the height of the left and right subtrees
    int left = recursive_find_height(n->left);
    int right = recursive_find_height(n->right);
    if(left>right){
        return 1+left;
    }else{
        return 1+right;
        }    
}

void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
  if (n == sentinel) { // If we reach the sentinel, we stop
        return; 
    }

    make_key_vector(n->left, v);
    v.push_back(n->key);
    make_key_vector(n->right, v);
}

BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, 
                                    const vector<void *> &vals,
                                    size_t first_index,
                                    size_t num_indices) const
{
    // Base case: no elements to insert
    if (num_indices == 0) {
        return sentinel; // Use the sentinel node instead of NULL
    }

    // Calculate the middle index
    size_t mid = first_index + num_indices / 2;

    // Create the new node
    BSTNode *node = new BSTNode();
    node->key = sorted_keys[mid];
    node->val = vals[mid];

    // Recursively create the left and right subtrees
    node->left = make_balanced_tree(sorted_keys, vals, first_index, mid - first_index);
    node->right = make_balanced_tree(sorted_keys, vals, mid + 1, num_indices - (mid - first_index + 1));

    // Set the parent pointers for the left and right children
    if (node->left != sentinel) {
        node->left->parent = node;
    }
    if (node->right != sentinel) {
        node->right->parent = node;
    }

    return node;
}
