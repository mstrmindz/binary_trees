// This function first initializes the root node to NULL, and then checks for invalid input parameters. If either array is NULL or size is 0, the function returns NULL to indicate failure.

// Otherwise, the function loops through each element of the array, calling the bst_insert function to insert each value into the BST. If bst_insert returns NULL, indicating a failure to insert a value, the function returns NULL to indicate failure.

// Finally, if all values are successfully inserted, the function returns a pointer to the root node of the created BST.

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 **/
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;

    if (array == NULL || size == 0) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        if (bst_insert(&root, array[i]) == NULL) {
            return NULL;
        }
    }

    return root;
}

