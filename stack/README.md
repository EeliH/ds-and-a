# Stack implementation

The stack is implemented using a linked list. For a linked list, the stack operations pop and push correspond to removing from and adding to the beginning of the list respectively. The API for these functions is as follows:

`void STACK_Push(Stack *stack, void *data);`

`void *STACK_Pop(Stack *stack);`

In addition, the code provides the following functions to create a Stack object to dynamic memory:

`Stack *STACK_Create();`

`void STACK_Free(Stack *list);`