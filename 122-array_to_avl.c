// This function first checks if the array pointer is NULL or if the size is zero, and returns NULL in such cases.

// Next, it initializes a root pointer to NULL.

// Then, it iterates through the array, calling the avl_insert function to insert each element of the array into the AVL tree.

// Finally, it returns the root pointer of the AVL tree.

// If a value of the array is already present in the tree, it will be ignored due to the implementation of avl_insert.

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    avl_t *root = NULL;

    for (size_t i = 0; i < size; i++) {
        avl_insert(&root, array[i]);
    }

    return root;
}

