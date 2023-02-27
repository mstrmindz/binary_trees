//This function takes in two pointers to binary tree nodes first and second. It returns a pointer to the lowest common ancestor node of the two given nodes. If no common ancestor was found, it returns NULL.

// The function starts by checking if either first or second are NULL, and returns NULL in that case. It then sets f to first, and enters a loop that iterates through each ancestor of f. For each ancestor f, it sets s to second and enters another loop that iterates through each ancestor of s. If f and s are equal at any point, then they have found a common ancestor, and the function returns a pointer to that node. If no common ancestor was found after checking all possible combinations of ancestors, the function returns NULL.

// Note that the function uses const pointers for the input nodes, but casts the result to a non-const pointer before returning. This is because the function returns a pointer to a node in the input tree, which may be modified by the caller.

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *f, *s;

    if (first == NULL || second == NULL)
        return NULL;

    f = first;
    while (f != NULL)
    {
        s = second;
        while (s != NULL)
        {
            if (f == s)
                return (binary_tree_t *)f;
            s = s->parent;
        }
        f = f->parent;
    }

    return NULL;
}

