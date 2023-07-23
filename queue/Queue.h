#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct {
  int num;
  Node *first;
  Node *last;
} Queue;

Queue *QUEUE_Create();
void QUEUE_Free(Queue *list);

void enqueue(Queue *list, void *data);
void *dequeue(Queue *list);

#endif