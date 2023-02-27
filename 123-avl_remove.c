#include "binary_trees.h"

/* Function to get the height of a tree */
int height(avl_t *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

/* Function to get the maximum of two integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Function to create a new AVL tree node */
avl_t *new_node(int value)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (node == NULL)
        return NULL;

    node->n = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->height = 1;

    return node;
}

/* Function to perform a right rotation on a subtree rooted with y */
avl_t *right_rotate(avl_t *y)
{
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    /* Perform rotation */
    x->right = y;
    y->left = T2;

    /* Update heights */
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    /* Update parent pointers */
    if (T2)
        T2->parent = y;
    x->parent = y->parent;
    y->parent = x;

    /* Return new root */
    return x;
}

/* Function to perform a left rotation on a subtree rooted with x */
avl_t *left_rotate(avl_t *x)
{
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    /* Perform rotation */
    y->left = x;
    x->right = T2;

    /* Update heights */
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    /* Update parent pointers */
    if (T2)
        T2->parent = x;
    y->parent = x->parent;
    x->parent = y;

    /* Return new root */
    return y;
}

/* Function to get the balance factor of a node */
int get_balance(avl_t *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

/* Function to find the node with minimum value in a given AVL tree */
avl_t *min_value_node(avl_t *node)
{
    avl_t *current = node;

    /* Loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Function to remove a node from an AVL tree */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Perform standard BST delete */
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        /* Node to be deleted found */

        /* Node has no children or only one child */
        if ((root->left == NULL) || (root->right == NULL))
        {
            avl_t *temp = root->left ? root

