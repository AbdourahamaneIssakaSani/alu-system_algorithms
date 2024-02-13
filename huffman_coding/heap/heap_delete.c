#include "heap.h"

void heap_delete_node(binary_tree_node_t *node, void (*free_data)(void *));

/**
* heap_delete - deletes an entire heap
* @heap: pointer to heap structure
* @free_data: pointer to a function that frees the data
*/
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	if (heap->root)
	{
		heap_delete_node(heap->root, free_data);
	}
	free(heap);
}

/**
* heap_delete_node - deletes an entire heap
* @node: pointer to heap structure
* @free_data: pointer to a function that frees the data
*/
void heap_delete_node(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (!node)
		return;
	heap_delete_node(node->left, free_data);
	heap_delete_node(node->right, free_data);
	if (free_data)
		free_data(node->data);
	free(node);
}
