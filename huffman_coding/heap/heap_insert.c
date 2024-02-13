#include "heap.h"

/**
 * heap_insert - inserts new node into min heap
 * @heap: pointer to heap structure
 * @data: pointer to data
 * Return: pointer to new node or NULL
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
    binary_tree_node_t *node = NULL, *parent = NULL;
    void *tmp = NULL;

    if (!heap)
        return (NULL);

    node = binary_tree_node(NULL, data);
    if (!node)
        return (NULL);
    if (!heap->root)
    {
        heap->root = node;
    }
    else
    {
        tmp = node->data;
        parent = heap->root;
        while (1)
        {
            if (parent->left == NULL)
            {
                parent->left = node, node->parent = parent;
                break;
            }
            else if (parent->right == NULL)
            {
                parent->right = node, node->parent = parent;
                break;
            }
            else if (heap->size % 2 == 0)
            {
                parent = parent->left;
            }
            else
            {
                parent = parent->right;
            }
            heap->size >>= 1;
        }
        node->data = tmp;
        while (node->parent && heap->data_cmp(node->data, node->parent->data) < 0)
        {
            tmp = node->parent->data;
            node->parent->data = node->data;
            node->data = tmp;
            node = node->parent;
        }
    }

    heap->size++;
    return (node);
}
