#include "heap.h"

/**
* heap_create - creates a heap data structure
* @data_cmp: pointer to a comparison function
* Return: pointer to the created heap_t
*/
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap = malloc(sizeof(heap_t));

	if (heap == NULL)
		return (NULL);

	heap->size = 0;
	heap->data_cmp = data_cmp;
	heap->root = NULL;

	return (heap);
}
