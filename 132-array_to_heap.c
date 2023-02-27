// This function takes an array and its size as input, and creates a Max Binary Heap tree from it using the heap_insert function. It iterates over the array and inserts each element into the heap. Finally, it returns a pointer to the root node of the created Binary Heap. If the input array is NULL or its size is 0, the function returns NULL.

#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}

