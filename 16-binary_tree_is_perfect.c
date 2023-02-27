//This function first checks if the tree is NULL, in which case it returns 0. It then calculates the height of the left and right subtrees and checks if they are equal. If not, the function returns 0. If both subtrees are NULL, the function returns 1, since a tree with no subtrees is considered perfect. If only one subtree is NULL, the function returns 0, since a perfect binary tree must have both subtrees at the same level. Finally, if both subtrees are not NULL, the function recursively checks if both are perfect. If so, the function returns 1, otherwise it returns 0.

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int height_left, height_right;

    if (tree == NULL)
        return (0);

    height_left = binary_tree_height(tree->left);
    height_right = binary_tree_height(tree->right);

    if (height_left != height_right)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (binary_tree_is_perfect(tree->left) &&
            binary_tree_is_perfect(tree->right));
}

