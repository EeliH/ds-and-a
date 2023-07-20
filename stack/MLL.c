#include <stdlib.h>
#include <stdio.h>

#include "MLL.h"

MutableLinkedList *MLL_Create()
{
    MutableLinkedList *ret = malloc(sizeof(MutableLinkedList));
    ret->num = 0;
    ret->first = NULL;
    ret->last = NULL;
    return ret;
}

void MLL_Free(MutableLinkedList *list)
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

void MLL_Initialize(MutableLinkedList *list, void *data)
{
    Node *elem = malloc(sizeof(Node));

    elem->data = data;
    elem->next = NULL;

    list->num = 1;
    list->first = elem;
    list->last = elem;
}

void MLL_Append(MutableLinkedList *list, void *data)
{
    if (list->first == NULL) {
        MLL_Initialize(list, data);
        return;
    }

    // New node
    Node *add = malloc(sizeof(Node));
    add->data = data;
    add->next = NULL;

    list->last->next = add;
    list->last = add;
    list->num++;
}

void MLL_grInitialize(MutableLinkedList *list, int len, void *data[len])
{
    if (len <= 0) {
        return;
    }

    MLL_Initialize(list, data[0]);
    len--;

    for (int i = 1; len > 0; len--, i++) {
        MLL_Append(list, data[i]);
    }
}

Node *MLL_NodeAt(MutableLinkedList *list, int idx) {
    if (list == NULL) {
        printf("%s ERROR: MLL is NULL\n", __func__);
        return NULL;
    }
    Node *ret = list->first;

    for (int i = 0; i < idx; ++i) {
        ret = ret->next;
    }

    return ret;
}

void MLL_Foreach(MutableLinkedList *list, void (*function)(void *function))
{
    for (int i = 0; i < list->num; ++i) {
        Node *cur = MLL_NodeAt(list, i);
        (*function)(cur->data);
    }
}

