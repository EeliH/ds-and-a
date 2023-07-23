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
