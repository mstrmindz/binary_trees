// The function takes a pointer to the root node of the tree to be rotated, and returns a pointer to the new root node of the tree after the rotation. If the tree is NULL, the function returns NULL.

// The rotation is performed by making the left child of the root the new root, and moving the old root to the right child of the new root. The left child of the new root becomes the right child of the old root, and the parent pointers of the nodes involved are updated accordingly. If the original root had a left child, but that child did not have a right child, then the original root's left child becomes the new root, and the original root becomes the right child of the new root.

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root = NULL;

    if (tree == NULL)
        return NULL;

    if (tree->left != NULL)
    {
        new_root = tree->left;
        tree->left = new_root->right;
        new_root->right = tree;
        new_root->parent = tree->parent;
        tree->parent = new_root;
        if (tree->left != NULL)
            tree->left->parent = tree;
    }

    return new_root;
}

