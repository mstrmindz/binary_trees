// This function first checks if tree is NULL. If it is, the function returns 0, since a NULL tree cannot be a valid AVL tree.

// Next, the function computes the difference between the heights of the left and right subtrees of tree. If the difference is greater than 1 or less than -1, the function returns 0, since this violates the height-balancing property of AVL trees.

// If the difference in heights is within the acceptable range, the function recursively checks if the left and right subtrees are also AVL trees. If either subtree is not an AVL tree, the function returns 0.

// If the tree passes all of these tests, the function returns 1, indicating that the tree is a valid AVL tree.

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height_diff;

    if (tree == NULL)
        return (0);

    height_diff = binary_tree_height(tree->left) - binary_tree_height(tree->right);

    if (height_diff > 1 || height_diff < -1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}

