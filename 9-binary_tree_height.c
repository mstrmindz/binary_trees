// This function recursively calculates the height of the binary tree by traversing the left and right subtrees and returning the maximum height. The base case is when the tree pointer is NULL, in which case the function returns 0.

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

