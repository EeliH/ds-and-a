#ifndef MUTABLELINKEDLIST_H
#define MUTABLELINKEDLIST_H

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct {
  int num;
  Node *first;
  Node *last;
} MutableLinkedList;

MutableLinkedList *MLL_Create();
void MLL_Free(MutableLinkedList *list);

#endif