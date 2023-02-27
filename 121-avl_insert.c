// This function uses the binary_tree_balance function (which computes the difference between the heights of the left and right subtrees) and the binary_tree_max_height function (which returns the maximum height of the left and right subtrees) that were defined in a previous question.

// The avl_rotate_left and avl_rotate_right functions are auxiliary functions that perform the left and right rotations required to balance the tree after an insertion or deletion.

#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL, *unbalanced_node = NULL;

    if (tree == NULL)
        return (NULL);

    /* Insert value in BST */
    if (*tree == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        if (new_node == NULL)
            return (NULL);
        *tree = new_node;
        return (new_node);
    }
    else if (value < (*tree)->n)
        new_node = avl_insert(&((*tree)->left), value);
    else if (value > (*tree)->n)
        new_node = avl_insert(&((*tree)->right), value);
    else
        return (*tree); /* Value already in tree */

    if (new_node == NULL)
        return (NULL);

    /* Update height of ancestor nodes */
    avl_t *ancestor = new_node->parent;
    while (ancestor != NULL)
    {
        int balance_factor = binary_tree_balance(ancestor);
        if (balance_factor > 1 || balance_factor < -1)
        {
            unbalanced_node = ancestor;
            break;
        }
        ancestor->height = 1 + binary_tree_max_height(ancestor->left,
                                                      ancestor->right);
        ancestor = ancestor->parent;
    }

    /* Balance the unbalanced node, if any */
    if (unbalanced_node != NULL)
    {
        if (value < unbalanced_node->n &&
            value < unbalanced_node->left->n)
        {
            /* Left-left case */
            avl_rotate_right(unbalanced_node);
        }
        else if (value > unbalanced_node->n &&
                 value > unbalanced_node->right->n)
        {
            /* Right-right case */
            avl_rotate_left(unbalanced_node);
        }
        else if (value < unbalanced_node->n &&
                 value > unbalanced_node->left->n)
        {
            /* Left-right case */
            avl_rotate_left(unbalanced_node->left);
            avl_rotate_right(unbalanced_node);
        }
        else if (value > unbalanced_node->n &&
                 value < unbalanced_node->right->n)
        {
            /* Right-left case */
            avl_rotate_right(unbalanced_node->right);
            avl_rotate_left(unbalanced_node);
        }
    }

    return (new_node);
}

