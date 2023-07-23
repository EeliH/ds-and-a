#include <stdlib.h>
#include <stdio.h>

#include "MLLa.h"

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

void MLL_Prepend(MutableLinkedList *list, void *data)
{
    if (list->first == NULL) {
        MLL_Initialize(list, data);
        return;
    }

    // New node
    Node *add = malloc(sizeof(Node));
    add->data = data;

    add->next = list->first;
    list->first = add;
}

void MLL_grInitialize(MutableLinkedList *list, int len, void *data[len])
{
    if (len <= 0) {
        printf("%s ERROR: length negative\n", __func__);
        return;
    }

    MLL_Initialize(list, data[0]);
    len--;

    for (int i = 1; len > 0; len--, i++) {
        MLL_Append(list, data[i]);
    }
}

void *MLL_RemoveAt(MutableLinkedList *list, int idx)
{
    if (list == NULL) {
        printf("%s ERROR: MLL is NULL\n", __func__);
        return NULL;
    }
    Node *prev = NULL;
    Node *cur = list->first;

    // TODO: check for list length

    for (int i = 0; i < idx; ++i) {
        prev = cur;
        cur = cur->next;
    }
    // When we get here, cur holds the node to be removed.
    void *ret = cur->data;

    if (cur->next != NULL) {
        prev->next = cur->next;
        free(cur);
    } else {
        list->last = prev;
    }

    --list->num;

    return ret;
}


void *MLL_Pop(MutableLinkedList *list)
{
    Node *node = list->first;
    void *ret = node->data;

    list->first = node->next;

    free(node);

    --list->num;

    return ret;
}


Node *MLL_NodeAt(MutableLinkedList *list, int idx) {
    if (list == NULL) {
        printf("%s ERROR: MLL is NULL\n", __func__);
        return NULL;
    }
    Node *ret = list->first;

    // TODO: check for list length

    for (int i = 0; i < idx; ++i) {
        ret = ret->next;
    }

    return ret;
}

void MLL_Foreach(MutableLinkedList *list, void (*function)(void *))
{
    for (int i = 0; i < list->num; ++i) {
        Node *cur = MLL_NodeAt(list, i);
        (*function)(cur->data);
    }
}
