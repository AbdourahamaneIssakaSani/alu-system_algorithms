#include "pathfinding.h"
#include <sys/types.h>

static int *dists;
static vertex_t **from;
static vertex_t **verts;

#define STRDUP(x) ((str = strdup(x)) ? str : (exit(1), NULL))

/**
 * dijkstra_graph - uses Dijkstra's Algo to find path
 * @graph: pointer to graph struct
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 * Return: path queue or NULL
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	ssize_t i, d, j = -1;
	vertex_t *v;
	edge_t *e;
	queue_t *path = queue_create();
	char *str;

	if (!graph || !start || !target || !path)
		return (NULL);
	dists = calloc(graph->nb_vertices, sizeof(*dists));
	from = calloc(graph->nb_vertices, sizeof(*from));
	verts = calloc(graph->nb_vertices, sizeof(*verts));
	if (!dists || !from || !verts || !path)
		return (NULL);
	for (v = graph->vertices; v; v = v->next)
		verts[v->index] = v, dists[v->index] = INT_MAX;
	dists[start->index] = 0, from[start->index] = NULL;
	while (j != (ssize_t)target->index)
	{
		for (d = INT_MAX, j = -1, i = 0; i < (ssize_t)graph->nb_vertices; i++)
			if (dists[i] >= 0 && dists[i] < d)
				d = dists[i], j = i;
		if (j == -1)
			break;
		printf("Checking %s, distance from %s is %d\n",
			verts[j]->content, start->content, dists[j]);
		for (e = verts[j]->edges; e; e = e->next)
			if (dists[e->dest->index] >= 0 &&
				dists[j] + e->weight < dists[e->dest->index])
				dists[e->dest->index] = dists[j] + e->weight,
					from[e->dest->index] = verts[j];
		dists[j] = -1;
	}
	if (j != -1)
		for (queue_push_front(path, STRDUP(verts[j]->content));
			j != (ssize_t)start->index; j = from[j]->index)
			queue_push_front(path, STRDUP(from[j]->content));
	else
		path = (free(path), NULL);
	free(dists), free(from), free(verts);
	return (path);
}
