#include "heap.h"

void heapify_down(heap_t *heap, binary_tree_node_t *node);
void detach_node(binary_tree_node_t *node);

/**
* heap_extract - extracts the root value of a min heap
* @heap: pointer to heap structure
* Return: pointer to data or NULL
*/
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *node = NULL;

	void *data = NULL;


	if (!heap || !heap->root)
		return (NULL);

	data = heap->root->data;
	node = heap->root;

	if (heap->size == 1)
	{
		heap->root = NULL;
	}
	else
	{
		heapify_down(heap, node);
		detach_node(node);
	}

	free(node);
	heap->size--;

	return (data);
}

/**
* heapify_down - maintains heap property after extracting the root
* @heap: pointer to heap structure
* @node: pointer to the node where heapify starts
*/
void heapify_down(heap_t *heap, binary_tree_node_t *node)
{
	while (node->left || node->right)
	{
		binary_tree_node_t *child = (node->right &&
		heap->data_cmp(node->left->data, node->right->data) < 0)
									? node->left : node->right;

		if (heap->data_cmp(node->data, child->data) > 0)
		{
			node->data = child->data;
			node = child;
		}
		else
		{
			break;
		}
	}
}

/**
* detach_node - detaches a node from its parent
* @node: pointer to the node to be detached
*/
void detach_node(binary_tree_node_t *node)
{
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	node->parent = NULL;
}
