// Note that this implementation assumes that the input binary search tree is a bst_t struct, which is a derived type of binary_tree_t. The binary_tree_node function used here is the same as the one defined in the prompt.

bst_t *bst_insert(bst_t **tree, int value)
{
    if (*tree == NULL) { //if the tree is empty, create a new node as the root
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    bst_t *current = *tree;

    while (current != NULL) {
        if (value == current->n) { //if value is already present, ignore
            return current;
        }
        if (value < current->n) { //go left if value is less than current node
            if (current->left == NULL) { //if left child is NULL, insert value as new node
                current->left = binary_tree_node(current, value);
                return current->left;
            }
            current = current->left; //traverse left subtree
        }
        else { //go right if value is greater than or equal to current node
            if (current->right == NULL) { //if right child is NULL, insert value as new node
                current->right = binary_tree_node(current, value);
                return current->right;
            }
            current = current->right; //traverse right subtree
        }
    }

    return NULL; //in case of failure
}

