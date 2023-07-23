#ifndef MUTABLELINKEDLISTaccessories_H
#define MUTABLELINKEDLISTaccessories_H

#include "MLL.h"

void MLL_Initialize(MutableLinkedList *list, void *data);
void MLL_Append(MutableLinkedList *list, void *data);
void MLL_Prepend(MutableLinkedList *list, void *data);
void MLL_grInitialize(MutableLinkedList *list, int len, void *data[len]);

void *MLL_RemoveAt(MutableLinkedList *list, int i);
void *MLL_Pop(MutableLinkedList *list);

Node *MLL_NodeAt(MutableLinkedList *list, int i);

void MLL_Foreach(MutableLinkedList *list, void (*function)(void *));

#endif