#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "queues.h"
#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INT_MAX 2147483647

/**
* struct point_s - Structure storing coordinates
*
* @x: X coordinate
* @y: Y coordinate
*/
typedef struct point_s
{
	int x;

	int y;

} point_t;

queue_t *backtracking_array(char **map, int rows, int cols,

	point_t const *start, point_t const *target);

int backtrack(char **map, int rows, int cols, point_t const *target,

	int x, int y, queue_t *path);

queue_t *backtracking_graph(graph_t *graph,
vertex_t const *start, vertex_t const *target);

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,

	vertex_t const *target);

#endif /*PATHFINDING_H*/
