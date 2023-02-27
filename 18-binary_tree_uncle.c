// Explanation:

// First, we check if the node or its parent is NULL or if the parent of the parent is NULL. If any of these conditions is true, we return NULL as there is no uncle.
// If the node's parent is the left child of the grandparent, the uncle is the right child of the grandparent. If the node's parent is the right child of the grandparent, the uncle is the left child of the grandparent.
// We return the uncle node.

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    if (node->parent->parent->left == node->parent)
        return node->parent->parent->right;
    else
        return node->parent->parent->left;
}

