//This function recursively counts the number of nodes in the binary tree that have at least one child. It starts by checking if the current node is NULL, in which case it returns 0. If the current node has at least one child (i.e. it is not a leaf node), it increments the count by 1. It then recursively calls the function on the left and right subtrees of the current node, and adds their counts to the total count. Finally, it returns the total count.

size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t count = 0;

    if (tree->left != NULL || tree->right != NULL)
        count = 1;

    count += binary_tree_nodes(tree->left);
    count += binary_tree_nodes(tree->right);

    return count;
}

