#ifndef STACK_H
#define STACK_H

#include "MLL.h"
#include <stddef.h>

typedef MutableLinkedList Stack;
typedef Node Element;


void STACK_Push(Stack *stack, void *data);

Element *STACK_Top(Stack *stack);
Element *STACK_Pop(Stack *stack);

#endif
