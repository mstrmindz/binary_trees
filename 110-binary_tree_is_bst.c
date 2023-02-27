// In this implementation, i used a static variable prev to keep track of the previous node visited during the inorder traversal. We first check the left subtree recursively, then check the current node (by comparing its value to the previous node's value), and finally check the right subtree recursively. If at any point the BST property is violated, we return 0. If we successfully traverse the entire tree, we return 1.

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    static const binary_tree_t *prev; // pointer to previous node in inorder traversal

    if (tree == NULL)
        return (0);

    /* check left subtree */
    if (!binary_tree_is_bst(tree->left))
        return (0);

    /* check current node */
    if (prev != NULL && prev->n >= tree->n)
        return (0);
    prev = tree;

    /* check right subtree */
    if (!binary_tree_is_bst(tree->right))
        return (0);

    return (1);
}

