#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "Stack.h"

Stack *STACK_Create()
{
    Stack *ret = malloc(sizeof(Stack));
    ret->size = 0;
    ret->head = NULL;
    return ret;
}

void STACK_Free(Stack *stack)
{
    Frame *cur = stack->head;
    while (cur != NULL) {
        Frame *tmp = cur->next;
        free(cur);
        cur = tmp;
    }

    free(stack);
}

void STACK_Push(Stack *stack, void *data)
{
    Frame *new = malloc(sizeof(Frame));
    new->data = data;
    new->next = (stack->head != NULL) ? stack->head : NULL;
    stack->head = new;
    ++stack->size;
}

void *STACK_Pop(Stack *stack)
{
    if (stack->head == NULL) {
        printf("%s ERROR: stack is empty\n", __func__);
        return NULL;
    }
    Frame *frame = stack->head;
    void *ret = frame->data;
    stack->head = frame->next;
    free(frame);
    --stack->size;
    return ret;
}
