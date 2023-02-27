// The heap_insert function takes a double pointer to the root node of a Max Binary Heap and a value to insert, and returns a pointer to the newly created node or NULL on failure. If the address stored in root is NULL, the created node becomes the root node.

// The function first creates a new node using the heap_create function, which takes the node value, parent node, left child, and right child as parameters. If the function fails to allocate memory for the new node, it returns NULL.

// If the heap is empty, the new node becomes the root node, and the function returns the node pointer.

// If the heap is not empty, the function traverses the heap from the root node to find the first available position for the new node. The function always inserts nodes in a left-to-right fashion to maintain the complete tree property of the Max Binary Heap.

// After inserting the new node, the function calls heap_sift_up to restore the Max Binary Heap property. This function takes a node pointer and recursively swaps the node with its parent if the node's value is greater than the parent's value until the Max Binary Heap property is restored.

// Finally, the function returns the pointer to the newly created node.

#include <stdlib.h>

typedef struct heap_s {
    int n;
    struct heap_s *parent;
    struct heap_s *left;
    struct heap_s *right;
} heap_t;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

heap_t *heap_create(int n, heap_t *parent, heap_t *left, heap_t *right)
{
    heap_t *node = malloc(sizeof(heap_t));
    if (node == NULL) {
        return NULL;
    }

    node->n = n;
    node->parent = parent;
    node->left = left;
    node->right = right;

    if (left != NULL) {
        left->parent = node;
    }
    if (right != NULL) {
        right->parent = node;
    }

    return node;
}

void heap_sift_up(heap_t *node)
{
    if (node->parent == NULL) {
        return;
    }

    if (node->n > node->parent->n) {
        swap(&node->n, &node->parent->n);
        heap_sift_up(node->parent);
    }
}

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node = heap_create(value, NULL, NULL, NULL);
    if (node == NULL) {
        return NULL;
    }

    if (*root == NULL) {
        *root = node;
        return node;
    }

    heap_t *parent = *root;
    while (parent->left != NULL) {
        if (parent->right == NULL || parent->left->n >= parent->right->n) {
            parent = parent->left;
        } else {
            parent = parent->right;
        }
    }

    if (parent->left == NULL) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    node->parent = parent;
    heap_sift_up(node);

    return node;
}

