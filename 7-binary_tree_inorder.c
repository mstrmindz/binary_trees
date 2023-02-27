//This function recursively traverses the left subtree of the given tree, then performs the func function on the value in the current node, and finally recursively traverses the right subtree. This follows the in-order traversal order, where nodes are processed in ascending order of their values. The function checks for NULL input parameters and does nothing if either tree or func is NULL.

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_inorder(tree->left, func);
    func(tree->n);
    binary_tree_inorder(tree->right, func);
}

