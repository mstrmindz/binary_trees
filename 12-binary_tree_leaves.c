//This function recursively counts the number of leaves in a binary tree by traversing the tree using pre-order traversal. It checks if a node is a leaf by verifying if its left and right child pointers are NULL. If so, it returns 1, otherwise it returns the sum of the number of leaves in its left and right subtrees. If the input tree is NULL, the function returns 0.

size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->left == NULL && tree->right == NULL)
        return 1;

    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}

