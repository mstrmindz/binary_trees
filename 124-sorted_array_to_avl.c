// This function takes a sorted array and its size as input, and recursively builds an AVL tree from the array. The create_avl_tree function is a recursive helper function that takes a sub-array of the original array and builds an AVL tree from it. The start and end arguments specify the indices of the sub-array, and parent is a pointer to the parent node of the current sub-tree.

// The create_avl_tree function works by finding the middle element of the sub-array, creating a new AVL node with that value, and recursively building the left and right subtrees from the left and right sub-arrays. The parent pointer is set to the parent node of the current sub-tree, and the pointers to the left and right child nodes are updated.

// After creating the root node of the AVL tree, the sorted_array_to_avl function returns a pointer to it. If the input array is NULL or has a size of 0, the function returns NULL.

/**
 * sorted_array_to_avl - Build an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (create_avl_tree(array, 0, size - 1, NULL));
}

/**
 * create_avl_tree - Create an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @start: Starting index of the current sub-array
 * @end: Ending index of the current sub-array
 * @parent: Pointer to the parent node of the current sub-tree
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *create_avl_tree(int *array, int start, int end, avl_t *parent)
{
    int mid;
    avl_t *root;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    root = malloc(sizeof(avl_t));
    if (root == NULL)
        return (NULL);

    root->n = array[mid];
    root->parent = parent;
    root->left = create_avl_tree(array, start, mid - 1, root);
    root->right = create_avl_tree(array, mid + 1, end, root);

    if (root->left != NULL)
        root->left->parent = root;
    if (root->right != NULL)
        root->right->parent = root;

    return (root);
}

