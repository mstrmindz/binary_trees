// You can call this function by passing in a pointer to the root node of the binary tree, as well as a pointer to a function that takes an integer value as a parameter. The function will then traverse the tree in in-order fashion, calling the provided function for each node.

#include <stdlib.h>

/* Binary tree node structure */
typedef struct binary_tree_s binary_tree_t;
struct binary_tree_s
{
    int n;
    binary_tree_t *parent;
    binary_tree_t *left;
    binary_tree_t *right;
};

/* Function to traverse a binary tree in-order */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;
    binary_tree_inorder(tree->left, func);
    func(tree->n);
    binary_tree_inorder(tree->right, func);
}

