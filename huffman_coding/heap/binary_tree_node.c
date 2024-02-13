#include "heap.h"

/**
 * binary_tree_node - creates new node in binary tree
 * @parent: pointer to parent or NULL
 * @data: void pointer to data for this node
 * Return: pointer to new node or NULL on error
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node = calloc(1, sizeof(*node));

	if (!node)
		return (NULL);
	node->parent = parent;
	node->data = data;
	return (node);
}
