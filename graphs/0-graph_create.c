#include "graphs.h"


/**
* graph_create - allocates memory to store a graph_t structure
*
* Return: If memory allocation fails, return NULL.
* Otherwise, return a pointer to the allocated structure.
*/
graph_t *graph_create(void)
{
	graph_t *graph = malloc(sizeof(graph_t));

	if (graph == NULL)
		return (NULL);

	graph->nb_vertices = 0;
	graph->vertices = NULL;

	return (graph);

}
