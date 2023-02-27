// This function uses a queue to traverse the tree level by level. We start by adding the root node to the queue, and then we iterate through the queue until it's empty. For each node in the queue, we add its left and right children to the queue (if they exist), and then we call the func function on the node's value.

#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                           traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Return: None.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[10000] = {NULL};
	int front = 0, rear = -1, i;

	if (tree == NULL || func == NULL)
		return;

	queue[++rear] = (binary_tree_t *)tree;
	while (front <= rear)
	{
		if (queue[front]->left != NULL)
			queue[++rear] = queue[front]->left;

		if (queue[front]->right != NULL)
			queue[++rear] = queue[front]->right;

		func(queue[front++]->n);
	}
}

