// This function recursively checks if each node has either two children or no children. If any node has only one child or no children, it returns 0, indicating that the tree is not full. Otherwise, if all nodes have either two children or no children, it returns 1, indicating that the tree is full.

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If leaf node */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If both left and right subtrees are not NULL */
    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    /* We reach here when one subtree is NULL and the other is not */
    return (0);
}

