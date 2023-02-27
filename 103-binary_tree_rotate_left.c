// The function takes in a pointer to the root node of the tree to rotate. It returns a pointer to the new root node of the tree after the rotation.

// First, we check if the tree pointer is NULL. If it is, we simply return NULL.

// Then, we assign the tree->right node to a new variable new_root. If new_root is NULL, then there is nothing to rotate, and we simply return the original tree.

// We then update the tree->right pointer to new_root->left. If new_root->left is not NULL, we update its parent pointer to point to tree.

// Next, we update new_root->left to point to tree, and new_root->parent to point to tree->parent. We then update tree->parent to point to new_root.

// Finally, we return new_root, which is now the new root node of the tree after the rotation.

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL)
        return NULL;

    new_root = tree->right;
    if (new_root == NULL)
        return tree;

    tree->right = new_root->left;
    if (tree->right != NULL)
        tree->right->parent = tree;

    new_root->left = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return new_root;
}

