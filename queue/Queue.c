#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

Queue *QUEUE_Create()
{
    Queue *ret = malloc(sizeof(Queue));
    ret->num = 0;
    ret->first = NULL;
    ret->last = NULL;
    return ret;
}

void QUEUE_Free(Queue *list)
{
    // free memory of the elements
    Node *cur = list->first;
    while (cur != NULL) {
        Node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }

    // free memory of the list
    free(list);
}

void enqueue(Queue *list, void *data)
{
    Node *ret = malloc(sizeof(Node));
    ret->data = data;
    ret->next = NULL;

    if (list->num == 0) {
        list->first  = ret;
    } else {
        list->last->next = ret;
    }

    list->last = ret;

    ++list->num;
}

void *dequeue(Queue *list)
{
    if (list->num == 0) {
        printf("%s: QUEUE is empty", __func__);
        return NULL;
    }

    Node *node = list->first;
    void *ret = node->data;
    list->first = node->next;
    free(node);
    --list->num;
    return ret;
}
