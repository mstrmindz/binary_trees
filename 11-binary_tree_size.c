// This function recursively traverses the binary tree in a post-order manner, adding 1 for each node encountered. When it reaches the end of a branch (i.e., a NULL node), it returns 0, which is added to the count of the parent node. The final result is the size of the entire tree.

size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

