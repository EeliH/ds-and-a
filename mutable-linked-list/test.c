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

    MLL_Free(t);
}