//This function first checks if the node pointer is NULL. If it is, the function returns 0. Otherwise, the function checks if the node has no left or right child nodes, and returns 1 if it is a leaf node, otherwise 0.

int binary_tree_is_leaf(const binary_tree_t *node) {
    if (node == NULL) {
        return 0;
    }
    return (node->left == NULL && node->right == NULL);
}

