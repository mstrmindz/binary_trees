// This function recursively searches for a value in a Binary Search Tree by comparing the value with the current node's value. If the value is found, it returns the pointer to the node containing the value. Otherwise, it continues the search in the left or right subtree depending on the value being less than or greater than the current node's value, respectively. If the tree is NULL or if the value is not found, it returns NULL.

bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL) { // if tree is NULL or if value is not found, return NULL
        return NULL;
    }

    if (value == tree->n) { // if the value is found at the root node, return the root node
        return (bst_t *) tree;
    }

    if (value < tree->n) { // if the value is less than the root node, search the left subtree
        return bst_search(tree->left, value);
    }

    // if the value is greater than the root node, search the right subtree
    return bst_search(tree->right, value);
}

