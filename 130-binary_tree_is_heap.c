// The function binary_tree_is_heap takes a pointer to the root node of a binary tree and returns 1 if the tree is a valid Max Binary Heap, and 0 otherwise. If the input tree is NULL, the function returns 0.

// The function first checks if the tree is a complete tree using a breadth-first search algorithm. If the tree is not complete, the function immediately returns 0.

// If the tree is complete, the function then checks if the tree satisfies the Max Binary Heap property using a recursive helper function is_max_heap. This function takes a pointer to a node in the tree and the maximum value allowed in the subtree rooted at that node. The function checks if the node's value is less than or equal to the maximum value, and recursively checks if the left and right subtrees also satisfy the Max Binary Heap property.

// If the tree satisfies both the complete tree and Max Binary Heap properties, the function returns 1. Otherwise, it returns 0.

#include <stdbool.h>
#include <stddef.h>

typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

bool is_complete_tree(const binary_tree_t *tree)
{
    if (tree == NULL) {
        return true;
    }

    bool seen_null_node = false;
    binary_tree_t *queue[10000];
    size_t front = 0, rear = 0;

    queue[rear++] = (binary_tree_t *) tree;

    while (front < rear) {
        binary_tree_t *node = queue[front++];

        if (node == NULL) {
            seen_null_node = true;
        } else if (seen_null_node) {
            return false;
        } else {
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }

    return true;
}

bool is_max_heap(const binary_tree_t *tree, int max_val)
{
    if (tree == NULL) {
        return true;
    }

    if (tree->n > max_val) {
        return false;
    }

    return is_max_heap(tree->left, tree->n) && is_max_heap(tree->right, tree->n);
}

int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL) {
        return 0;
    }

    if (!is_complete_tree(tree)) {
        return 0;
    }

    return is_max_heap(tree, INT_MAX) ? 1 : 0;
}

