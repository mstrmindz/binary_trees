//This function takes a pointer to the parent node and an integer value as arguments. It first checks if the parent node is not NULL, returning NULL if it is. It then creates a new node with the given value and parent node using the binary_tree_node() function, returning NULL if this fails.
//If the parent node already has a right-child, the function updates the right-child's parent pointer to point to the new node and sets the new node's right-child to the old right-child. Finally, it sets the parent's right-child to the new node and returns a pointer to the new node. If the parent node does not already have a right-child, the function simply sets the parent's right-child to the new node and returns a pointer to the new node.

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    if (parent == NULL) {
        return NULL;
    }

    binary_tree_t *new_node = binary_tree_node(parent, value);

    if (new_node == NULL) {
        return NULL;
    }

    if (parent->right != NULL) {
        parent->right->parent = new_node;
        new_node->right = parent->right;
    }

    parent->right = new_node;

    return new_node;
}
