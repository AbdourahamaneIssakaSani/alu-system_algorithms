#ifndef _QUEUES_H_
#define _QUEUES_H_

/**
 * struct queue_node_s - Queue node structure
 *
 * @ptr: Data of the queue
 * @next: Pointer to the next node of the queue
 * @prev: Pointer to the previous node of the queue
 */
typedef struct queue_node_s
{
	void			*ptr;
	struct queue_node_s	*next;
	struct queue_node_s	*prev;
} queue_node_t;

/**
 * struct queue_s - Queue structure
 *
 * @front: Pointer to the front node of the queue
 * @back: Pointer to the back node of the queue
 */
typedef struct queue_s
{
	queue_node_t *front;
	queue_node_t *back;
} queue_t;


/*
 * FUNCTIONS
 */

/**
 * queue_create - Initializes a queue structure
 *
 * Return: A pointer to the allocated structure, NULL on failure
 */
queue_t *queue_create(void);

/**
 * queue_push_back - Pushes an element at the back of a queue
 *
 * @queue: Pointer to the queue
 * @ptr: Data to store in the new node
 *
 * Return: A pointer to the created node, NULL on failure
 */
queue_node_t *queue_push_back(queue_t *queue, void *ptr);

/**
 * queue_push_front - Pushes an element at the front of a queue
 *
 * @queue: Pointer to the queue
 * @ptr: Data to store in the new node
 *
 * Return: A pointer to the created node, NULL on failure
 */
queue_node_t *queue_push_front(queue_t *queue, void *ptr);

/**
 * dequeue - Pops out the front node of a queue
 *
 * @queue: Pointer to the queue
 *
 * Return: A pointer to the data of the poped node, NULL on failure
 */
void *dequeue(queue_t *queue);

/**
 * queue_delete - Deallocates a queue
 *
 * @queue: Pointer to the queue to be deleted
 */
void queue_delete(queue_t *queue);

#endif /* !_QUEUES_H_ */
