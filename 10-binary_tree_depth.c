//This function traverses up the parent pointers of the given node until it reaches the root node, counting the number of traversals to calculate the depth of the node.

size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (tree == NULL)
        return depth;

    while (tree->parent != NULL)
    {
        depth++;
        tree = tree->parent;
    }

    return depth;
}

