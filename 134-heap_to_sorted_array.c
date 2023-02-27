// This function converts a Max Binary Heap to a sorted array of integers in descending order, and returns a pointer to the array. It takes as input a pointer to the root node of the heap to convert, and a pointer to the variable that will store the size of the array.

// The function first checks if the input heap pointer and size pointer are not NULL. If either of them is NULL, the function returns NULL.

// The function then determines the size of the array by calling the binary_tree_size helper function. It allocates memory for the array, and if the allocation fails, the function returns NULL.

// Finally, the function extracts each element from the heap and adds it to the array. Since we are using a Max Heap, the extracted elements are in descending order. The function returns a pointer to the sorted array of integers.

// If the function fails, it returns NULL.

#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to the sorted array of integers, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array, index;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);
	array = malloc(*size * sizeof(int));
	if (!array)
		return (NULL);

	for (index = 0; index < (int)*size; index++)
		array[index] = heap_extract(&heap);

	return (array);
}

