#include <stdio.h>

#include "Stack.h"

int main()
{
    Stack *stack = STACK_Create();
    STACK_Push(stack, "A");
    STACK_Push(stack, "B");
    STACK_Push(stack, "C");
    STACK_Push(stack, "D");
    printf("top of the stack: %s\n", (char *) stack->head->data);
    STACK_Pop(stack);
    STACK_Pop(stack);
    printf("top of the stack: %s\n", (char *) stack->head->data);
    STACK_Free(stack);
}