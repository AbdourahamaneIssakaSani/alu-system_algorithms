#include "graphs.h"

/*@gogomillan*/

/**
* get_vertex_index - A function that fetches an vertex existing in graph by
* index
* @graph: A pointer to the graph
* @index: The index identifying the vertex
*
* Return: vertex on success,  NULL on failure
*/
vertex_t *get_vertex_index(const graph_t *graph, size_t index)
{
	vertex_t *node;

	if (index > graph->nb_vertices)
		return (NULL);
	node = graph->vertices;
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->index == index)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
* dfs_util - A function that goes through a graph using the
* depth -first algorithm.
* @v: index of the vertex
* @visited: array of nodes marked visited or not
* @curr_depth: depth of the curreent node
* @depth: max depth of the graph
* @graph: A pointer to the graph to traverse
* @action: A pointer to a function to be called for each visited vertex.
* Return: The biggest vertex curr_depth , or 0 on failure
*/
void dfs_util(int v, size_t *visited, size_t curr_depth, size_t *depth,

			const graph_t *graph, void (*action)(const vertex_t *v, size_t curr_depth))
{
	vertex_t *dest, *curr;
	edge_t *edge;

	curr = get_vertex_index(graph, v);
	if (curr != NULL && visited[v] != EXPLORED)
	{
		action(curr, curr_depth);
		if (curr_depth > *depth)
			*depth = curr_depth;
		visited[v] = EXPLORED;
		edge = curr->edges;
		while (edge != NULL)
		{
			dest = edge->dest;
			if (visited[dest->index] != EXPLORED)
			{
				dfs_util(dest->index, visited, curr_depth + 1,
						depth, graph, action);
			}
			edge = edge->next;
		}
	}
}

/**
* depth_first_traverse - A function that goes through a graph using the
* depth -first algorithm.
* @graph: A pointer to the graph to traverse
* @action: A  pointer to a function to be called for each visited vertex.
* Return: The max depth , or 0 on failure
*/
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth))
{
	size_t depth = 0;
	size_t *visited;
	vertex_t *curr;

	if (graph != NULL)
	{
		visited = calloc(graph->nb_vertices, sizeof(size_t));

		curr = graph->vertices;
		if (curr)
		{
			if (visited[curr->index] == UNEXPLORED)
				dfs_util(curr->index, visited, 0, &depth,
						graph, action);
			curr = curr->next;
		}
		free(visited);
	}
	return (depth);
}
