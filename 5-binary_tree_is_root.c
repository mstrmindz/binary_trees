//Explanation:The function takes a pointer to a binary tree node as input and returns an integer indicating whether the node is a root (1) or not (0).
//If the input node is NULL, the function immediately returns 0.
//Otherwise, the function checks if the input node's parent pointer is NULL. If so, it means the node has no parent and is therefore a root, so the function returns 1. If not, it means the node has a parent and is not a root, so the function returns 0.

int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL)
        return (0);
    return (node->parent == NULL);
}

