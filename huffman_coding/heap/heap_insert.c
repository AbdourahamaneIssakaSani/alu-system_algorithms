#include "heap.h"


void heap_insert_recursive(heap_t *heap,
binary_tree_node_t *root, binary_tree_node_t *node);
void heapify(heap_t *heap, binary_tree_node_t *node);


/**
* heap_insert - inserts new node into min heap
* @heap: pointer to heap structure
* @data: pointer to data
* Return: pointer to new node or NULL
*/
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node = NULL;

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
		heap_insert_recursive(heap, heap->root, node);
		heapify(heap, node);
	}

	heap->size++;

	return (node);
}

/**
* heap_insert_recursive - recursively inserts new node into min heap
* @heap: pointer to heap structure
* @root: current root
* @node: pointer to node to insert
*/
void heap_insert_recursive(heap_t *heap,
binary_tree_node_t *root, binary_tree_node_t *node)
{
	if (!root->left)
	{
		root->left = node;
		node->parent = root;
	}
	else if (!root->right)
	{
		root->right = node;
		node->parent = root;
	}
	else if (heap->size % 2 == 0)
	{
		heap_insert_recursive(heap, root->left, node);
	}
	else
	{
		heap_insert_recursive(heap, root->right, node);
	}
}

/**
* heapify - maintains heap property after insertion
* @heap: pointer to heap structure
* @node: pointer to node to heapify
*/
void heapify(heap_t *heap, binary_tree_node_t *node)
{
	void *tmp = NULL;

	while (node->parent && heap->data_cmp(node->data, node->parent->data) < 0)
	{
		tmp = node->parent->data;
		node->parent->data = node->data;
		node->data = tmp;
		node = node->parent;
	}
}
