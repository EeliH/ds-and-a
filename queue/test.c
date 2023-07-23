#include <stdio.h>

#include "Queue.h"

int main()
{
    Queue *queue = QUEUE_Create();
    enqueue(queue, "A");
    enqueue(queue, "B");
    enqueue(queue, "C");
    enqueue(queue, "D");
    printf("first in queue: %s\n", (char *) queue->first->data);
    printf("last in queue: %s\n", (char *) queue->last->data);
    dequeue(queue);
    dequeue(queue);
    printf("first in queue: %s\n", (char *) queue->first->data);
    printf("last in queue: %s\n", (char *) queue->last->data);
    QUEUE_Free(queue);
}