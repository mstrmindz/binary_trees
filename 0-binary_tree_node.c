//This function creates a new binary tree node with the given value and parent node, and sets the left and right child pointers to NULL. If the malloc() call fails to allocate memory for the new node, the function returns NULL to indicate the failure.

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
