//This function performs a pre-order traversal of the binary tree rooted at tree, calling the function func on each node in the traversal. The func function takes an integer parameter, which is the value of the node being visited. The traversal order is root-left-right.
//If tree or func is NULL, the function does nothing.

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}

