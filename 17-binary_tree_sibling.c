// The function takes a pointer to a binary tree node node and returns a pointer to its sibling node. If node is NULL or node has no parent, the function returns NULL. If node has a parent, but no sibling, the function also returns NULL. If node has a sibling, the function returns a pointer to the sibling node.

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    /* If node or parent is NULL, return NULL */
    if (node == NULL || node->parent == NULL)
        return NULL;

    /* Check if node is the left or right child of its parent */
    if (node == node->parent->left)
        return node->parent->right;
    else if (node == node->parent->right)
        return node->parent->left;
    else
        return NULL; /* node has no sibling */
}

