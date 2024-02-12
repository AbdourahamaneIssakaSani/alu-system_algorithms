#include "graphs.h"
#include <string.h>
#include <stdlib.h>

vertex_t *create_vertex(const char *str);

/**
 * graph_add_vertex - adds a vertex to the graph
 * @graph: pointer to graph type
 * @str: string value for new vertex
 * Return: pointer to vertex or null
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex_ptr, *prev_vertex_ptr, *vertex;

	if (graph == NULL || str == NULL)
	{
		return (NULL);
	}

	vertex_ptr = graph->vertices;

	/* Check if the vertex with the str already exists */
	while (vertex_ptr)
	{
		if (strcmp(vertex_ptr->content, str) == 0)
		{
			return (NULL);
		}

		prev_vertex_ptr = vertex_ptr;
		vertex_ptr = vertex_ptr->next;
	}

	/*Create a new vertex*/
	vertex = create_vertex(str);

	if (vertex == NULL)
	{
		return (NULL);
	}


	if (graph->nb_vertices == 0)
	{
		graph->vertices = vertex;
		vertex->index = 0;
	}
	else
	{
		prev_vertex_ptr->next = vertex;
		vertex->index = prev_vertex_ptr->index + 1;
	}


	graph->nb_vertices += 1;

	return (vertex);
}

/**
 * create_vertex - create a new vertex
 * @str: string value for the new vertex
 * Return: a pointer to the new vertex
 */
vertex_t *create_vertex(const char *str)
{
	vertex_t *vertex = malloc(sizeof(vertex_t));

	if (vertex == NULL)
	{
		return (NULL);
	}

	vertex->content = strdup(str);
	vertex->index = 0;
	vertex->edges = NULL;
	vertex->nb_edges = 0;
	vertex->next = NULL;

	return (vertex);
}
