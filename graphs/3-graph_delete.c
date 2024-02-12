#include "graphs.h"

/**
* graph_delete - deallocate memory for a graph
* @graph: pointer to graph type
*/
void graph_delete(graph_t *graph)
{
	vertex_t *vertex_ptr, *temp_vertex;
	edge_t *edge_ptr, *temp_edge;

	if (graph == NULL)
	{
		return;
	}

	vertex_ptr = graph->vertices;

	while (vertex_ptr)
	{
		temp_vertex = vertex_ptr;
		vertex_ptr = vertex_ptr->next;
		free(temp_vertex->content);

		edge_ptr = temp_vertex->edges;
		while (edge_ptr)
		{
			temp_edge = edge_ptr;
			edge_ptr = edge_ptr->next;
			free(temp_edge);
		}
		free(temp_vertex);
	}

	free(graph);
}
