#include <stdio.h>


#include "MLL.h"

void printString(void *str)
{
    printf("%s\n", (char*) str);
}

int main()
{
    MutableLinkedList* t = MLL_Create();

    char* strings[3] = {"moi", "mitä", "kuuluu"};
    MLL_grInitialize(t, 3, (void**) strings);

    MLL_Foreach(t, printString);
    printf("length: %d\n", t->num);

    char *rem = (char *) MLL_RemoveAt(t, 2);
    printf("just removed: %s\n", rem);

    MLL_Foreach(t, printString);
    printf("length: %d\n", t->num);

    MLL_Pop(t);
    MLL_Foreach(t, printString);

    MLL_Free(t);
}