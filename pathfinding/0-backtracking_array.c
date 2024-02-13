#include "pathfinding.h"

/**
* backtracking_array - backtracking algorithm
* @map: map
* @rows: number of rows
* @cols: number of columns
* @start: start point
* @target: target point
* Return: queue of points
*/
queue_t *backtracking_array(char **map, int rows, int cols,

							point_t const *start, point_t const *target)
{
	queue_t *path = queue_create();

	if (!map || !*map || rows < 1 || cols < 1 || !start || !target || !path)
		return (NULL);

	if (backtrack(map, rows, cols, target, start->x, start->y, path))
		return (path);

	while (path->front)
		free(dequeue(path));
	free(path);

	return (NULL);
}

/**
* backtrack - backtracking algorithm
* @map: map
* @rows: number of rows
* @cols: number of columns
* @target: target point
* @x: current x
* @y: current y
* @path: path
* Return: 1 on success, 0 on failure
*/
int backtrack(char **map, int rows, int cols, point_t const *target,

			int x, int y, queue_t *path)
{
	point_t *point = malloc(sizeof(*point));

	if (!point)
	{
		while (path->front)
			free(dequeue(path));
		free(path);
		return (0);
	}

	if (x < 0 || x >= cols || y < 0 || y >= rows || map[y][x] != '0')
	{
		free(point);
		return (0);
	}

	map[y][x] = '1';

	point->x = x;
	point->y = y;

	queue_push_front(path, point);
	printf("Checking coordinates [%d, %d]\n", x, y);

	if (x == target->x && y == target->y)
		return (1);


	if (backtrack(map, rows, cols, target, x + 1, y, path) ||
		backtrack(map, rows, cols, target, x - 1, y, path) ||
		backtrack(map, rows, cols, target, x, y + 1, path) ||
		backtrack(map, rows, cols, target, x, y - 1, path))
		return (1);

	free(dequeue(path));

	return (0);
}
