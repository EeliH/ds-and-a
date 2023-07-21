#ifndef STACK_H
#define STACK_H

typedef struct Frame {
  void *data;
  struct Frame *next;
} Frame;

typedef struct {
  int size;
  Frame *head;
} Stack;

Stack *STACK_Create();
void STACK_Free(Stack *list);

void STACK_Push(Stack *stack, void *data);
void *STACK_Pop(Stack *stack);

#endif