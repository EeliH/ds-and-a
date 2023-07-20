#include "Stack.h"

void STACK_Push(Stack *stack, void *data)
{
    MLL_Append(stack, data);
}

Element *STACK_Top(Stack *stack)
{
    return MLL_NodeAt(stack, stack->num - 1);
}

Element *STACK_Pop(Stack *stack)
{
    // TODO: Implement
    return NULL;
}
