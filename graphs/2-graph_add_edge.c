
#include "graphs.h"

vertex_t *get_vertex(graph_t *graph, const char *str);

edge_t *create_edge(vertex_t *src_vertex,
					vertex_t *dest_vertex, edge_type_t type);

/**
* graph_add_edge - adds an edge between two vertices to the graph
* @graph: pointer to graph type
* @src: string value of source vertex
* @dest: string value of destination vertex
* @type: type of edge
* UNIDIRECTIONAL: one way edge connection between src and dest
* BIDIRECTIONAL: two way edge connection between src and dest
*
* Return: 1 on success, 0 on failure
*/
int graph_add_edge(graph_t *graph, const char *src,

				const char *dest, edge_type_t type)
{
	vertex_t *src_vertex, *dest_vertex;

	edge_t *edge;

	if (graph == NULL || src == NULL || dest == NULL)
	{
		return (0);
	}

	if (type != UNIDIRECTIONAL && type != BIDIRECTIONAL)
	{
		return (0);
	}

	src_vertex = get_vertex(graph, src);
	dest_vertex = get_vertex(graph, dest);

	if (src_vertex == NULL || dest_vertex == NULL)
	{
		return (0);
	}

	edge = create_edge(src_vertex, dest_vertex, type);
	if (edge == NULL)
	{
		return (0);
	}

	src_vertex->nb_edges += 1;
	dest_vertex->nb_edges += 1;

	return (1);
}

/**
* get_vertex - get a vertex from the graph
* @graph: pointer to graph type
* @str: string value of the vertex
*
* Return: pointer to vertex or NULL
*/
vertex_t *get_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex_ptr;

	vertex_ptr = graph->vertices;

	while (vertex_ptr)
	{
		if (strcmp(vertex_ptr->content, str) == 0)
		{
			return (vertex_ptr);
		}
		vertex_ptr = vertex_ptr->next;
	}

	return (NULL);
}

/**
* create_edge - creates an edge between two vertices
* @src_vertex: pointer to source vertex
* @dest_vertex: pointer to destination vertex
* @type: type of edge
* UNIDIRECTIONAL: one way edge connection between src and dest
* BIDIRECTIONAL: two way edge connection between src and dest
*
* Return: pointer to the new edge
*/
edge_t *create_edge(vertex_t *src_vertex,
					vertex_t *dest_vertex, edge_type_t type)
{
	edge_t *edge = malloc(sizeof(edge_t));

	if (edge == NULL)
	{
		return (NULL);
	}

	edge->dest = dest_vertex;
	edge->next = NULL;

	if (type == BIDIRECTIONAL)
	{

		edge_t *reverse_edge = malloc(sizeof(edge_t));

		if (reverse_edge == NULL)
		{
			free(edge);
			return (NULL);
		}

		reverse_edge->dest = src_vertex;
		reverse_edge->next = dest_vertex->edges;
		dest_vertex->edges = reverse_edge;
	}

	edge->next = src_vertex->edges;
	src_vertex->edges = edge;

	return (edge);
}
