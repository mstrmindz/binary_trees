// Note that this implementation assumes that the binary search tree is valid, and that there are no duplicate values.

bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL) { // Empty tree
        return root;
    }

    if (value < root->n) { // Value to be deleted is smaller than the current node's value
        root->left = bst_remove(root->left, value);
    } else if (value > root->n) { // Value to be deleted is greater than the current node's value
        root->right = bst_remove(root->right, value);
    } else { // Value to be deleted is equal to the current node's value
        if (root->left == NULL) { // Node has one or no child
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) { // Node has one child
            bst_t *temp = root->left;
            free(root);
            return temp;
        }
        // Node has two children
        bst_t *temp = root->right;
        while (temp && temp->left) { // Find the in-order successor
            temp = temp->left;
        }
        root->n = temp->n; // Replace the value of the node to be deleted with the value of the in-order successor
        root->right = bst_remove(root->right, temp->n); // Delete the in-order successor
    }

    return root;
}

