// This function extracts the root node of a Max Binary Heap and returns its value. It first checks if the input root pointer is NULL or points to a NULL node, and returns 0 if it does. If the root node is the only node in the heap, it is freed and the function returns the value of the root node.

// If there are other nodes in the heap, the last node in level-order traversal is found using the get_last_node helper function. This node is detached from its parent, and its pointers are updated to point to the root node's left and right children. The root node is freed and replaced with the last node, and the heap property is restored using the heapify_down helper function.

// If the function fails, it returns 0.

#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of heap
 *
 * Return: the value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *parent;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	last_node = get_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	parent = last_node->parent;
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	last_node->parent = NULL;
	last_node->left = (*root)->left;
	last_node->right = (*root)->right;

	if (last_node->left)
		last_node->left->parent = last_node;
	if (last_node->right)
		last_node->right->parent = last_node;

	free(*root);
	*root = last_node;
	heapify_down(*root);

	return (value);
}

