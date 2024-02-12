#include "graphs.h"

/*@gogomillan*/

/**
* createqueue_t - A function that creates a queue
* Return: queue created
*/
queue_t *createqueue_t()
{
	queue_t *q = malloc(sizeof(queue_t));

	q->front = -1;
	q->rear = -1;
	return (q);
}

/**
* enqueue - A function that appends the item in queue
* @q: queue
* @value: value to be stored
*/
void enqueue(queue_t *q, int value)
{
	if (q->rear == (SIZE - 1))
		printf("\nqueue_t is Full!!");
	else
	{
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}

/**
* dequeue - A function that fetches first item in queue
* @q: queue
* @peek: whether to perform dequeue or just a peek
* Return: first item in queue on success,  -1 on failure
*/
int dequeue(queue_t *q, int peek)
{
	int item;

	if (q->rear == -1)
	{
		printf("queue_t is empty");
		item = -1;
	}
	else
	{
		if (peek)
			return (q->items[q->front]);
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear)
		{
			q->front = q->rear = -1;
		}
	}
	return (item);
}

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
* breadth_first_traverse - A function that goes through a graph using the
* breadth -first algorithm.
* @graph: A pointer to the graph to traverse
* @action: A  pointer to a function to be called for each visited vertex.
* Return: The max breadth , or 0 on failure
*/
size_t breadth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t breadth))
{
	size_t breadth = 0, *visited;
	int index = 0;

	vertex_t *curr, *dest;
	edge_t *edge;
	queue_t *q;

	if (graph == NULL || graph->nb_vertices == 0 || graph->vertices == NULL)
		return (0);
	visited = calloc(graph->nb_vertices, sizeof(size_t)), q = createqueue_t();
	curr = graph->vertices, enqueue(q, curr->index), enqueue(q, LEVELBREAK);
	while (q->rear != -1)
	{
		index = dequeue(q, 0);
		if (index == LEVELBREAK)
		{
			breadth++;
			enqueue(q, LEVELBREAK);
			if (dequeue(q, 1) == LEVELBREAK)
				break;
			continue;
		}
		curr = get_vertex_index(graph, index);
		if (visited[curr->index] != EXPLORED)
		{
			visited[curr->index] = EXPLORED;
			action(curr, breadth);
			edge = curr->edges;
			while (edge)
			{
				dest = edge->dest;
				if (dest && visited[dest->index] == UNEXPLORED)
					enqueue(q, dest->index), visited[dest->index] = BACKTRACK;
				edge = edge->next;
			}
		}
	}
	free(visited), free(q);
	return (breadth - 1);
}
