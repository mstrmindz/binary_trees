// This function uses a queue to traverse the tree in a level-order fashion. At each node, it checks if the left and right child exist, and if they do, it pushes them onto the queue. If a node does not have a left or right child, it sets a flag to indicate that this is the last level of the tree.

// If a node at the last level of the tree has a left child but not a right child, the tree is not complete. If a node at the last level of the tree does not have a left child, all subsequent nodes should also not have children. If any subsequent nodes have children, the tree is not complete. If we traverse the entire tree and these conditions are not violated, the tree is complete.

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    queue_t *queue = NULL;
    const binary_tree_t *node;
    int is_complete = 1, is_last_level = 0;

    if (tree == NULL)
        return (0);

    queue = queue_push(queue, (void *)tree);
    while (queue)
    {
        node = (const binary_tree_t *)queue->item;
        queue = queue_pop(queue);

        if (node->left)
        {
            if (is_last_level)
                return (0);
            queue = queue_push(queue, (void *)node->left);
        }
        else
            is_last_level = 1;

        if (node->right)
        {
            if (is_last_level)
                return (0);
            queue = queue_push(queue, (void *)node->right);
        }
        else
            is_last_level = 1;
    }

    return (is_complete);
}

