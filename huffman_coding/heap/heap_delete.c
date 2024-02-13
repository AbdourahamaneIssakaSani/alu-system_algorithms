#include "heap.h"

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
