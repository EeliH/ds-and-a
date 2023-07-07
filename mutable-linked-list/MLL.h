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

void MLL_Initialize(MutableLinkedList *list, void *data);
void MLL_Append(MutableLinkedList *list, void *data);
void MLL_grInitialize(MutableLinkedList *list, int len, void *data[len]);

Node *MLL_NodeAt(MutableLinkedList *list, int i);

void MLL_Foreach(MutableLinkedList *list, void (*function)(void *));

#endif