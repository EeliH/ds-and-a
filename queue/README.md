# FIFO queue

The code implements a first-in-first-out (FIFO) queue using mutable linked lists. In mutable linked lists, enqueue and dequeue correspond to adding to the end of the list and removing from the beginning of the list respectively. The API for enqueue and dequeue is as follows

`void enqueue(Queue *list, void *data);`

`void *dequeue(Queue *list);`

In addition, the code provides the following functions to create a Queue object in dynamic memory:

`Queue *QUEUE_Create();`

`void QUEUE_Free(Queue *list);`