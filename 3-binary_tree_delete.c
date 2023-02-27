//This function first checks if the tree pointer is NULL. If it is, the function does nothing and returns. Otherwise, the function recursively deletes the left and right subtrees, and finally frees the root node.

void binary_tree_delete(binary_tree_t *tree) {
    if (tree == NULL) {
        return;
    }
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}

