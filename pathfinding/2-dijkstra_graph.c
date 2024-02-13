#include "pathfinding.h"


int initialize_dijkstra(graph_t *graph,
vertex_t const *start, vertex_t const *target,

						queue_t *queue, size_t **dist, size_t **prev, char **visited);

/**
* dijkstra_graph - Dijkstra's algorithm
* @graph: graph
* @start: start vertex
* @target: target vertex
* Return: queue of vertices
*/
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,

						vertex_t const *target)
{
	queue_t *queue = queue_create();
	size_t *dist = NULL, *prev = NULL;
	char *visited = NULL;
	vertex_t *vertex = (vertex_t *)dequeue(queue);

	if (!graph || !start || !target || !queue)
		return (NULL);

	if (!initialize_dijkstra(graph, start, target, queue, &dist, &prev, &visited))
		goto cleanup;

	while (queue->front)
	{

		if (vertex == target)
			break;
		if (visited[vertex->index])
			continue;
		visited[vertex->index] = 1;
		update_distances(graph, vertex, queue, dist, prev);
	}

	free(visited);
	free(queue);
	return (path(graph, start, target, prev, dist));

cleanup:
	free(visited);
	free(dist);
	free(prev);
	while (queue->front)
		free(dequeue(queue));
	free(queue);
	return (NULL);
}

/**
* initialize_dijkstra - Initialize Dijkstra's algorithm
* @graph: graph
* @start: start vertex
* @target: target vertex
* @queue: queue
* @dist: array of distances
* @prev: array of previous vertices
* @visited: array of visited vertices
* Return: 1 on success, 0 on failure
*/
int initialize_dijkstra(graph_t *graph,
vertex_t const *start, vertex_t const *target,

						queue_t *queue, size_t **dist, size_t **prev, char **visited)
{
	size_t i;

	*dist = malloc(graph->nb_vertices * sizeof(**dist));
	*prev = malloc(graph->nb_vertices * sizeof(**prev));
	*visited = calloc(graph->nb_vertices, sizeof(**visited));
	if (!*dist || !*prev || !*visited)
		return (0);

	for (i = 0; i < graph->nb_vertices; ++i)
	{
		(*dist)[i] = (size_t)-1;
		(*prev)[i] = (size_t)-1;
	}
	(*dist)[start->index] = 0;

	if (!enqueue(queue, (void *)start))
		return (0);

	return (1);
}

/**
* update_distances - Update distances for Dijkstra's algorithm
* @graph: graph
* @vertex: current vertex
* @queue: queue
* @dist: array of distances
* @prev: array of previous vertices
*/
void update_distances(graph_t *graph, vertex_t *vertex, queue_t *queue,
					size_t *dist, size_t *prev)
{
	edge_t *edge;
	vertex_t *v;

	for (edge = vertex->edges; edge; edge = edge->next)
	{
		v = edge->dest;
		if (dist[v->index] > dist[vertex->index] + edge->weight)
		{
			dist[v->index] = dist[vertex->index] + edge->weight;
			prev[v->index] = vertex->index;
			if (!enqueue(queue, (void *)v))
				return;
		}
	}
}
