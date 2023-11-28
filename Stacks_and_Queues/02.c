/*
2) String Message Stack.  
WTD: Implement a stack that specializes in storing and retrieving string messages in a 
FIFO manner.  
(e.g: I/P: Enstack "HELLO", Enstack "WORLD" ; O/P: Destack - "HELLO", Destack 
- "WORLD") 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char** str; // declaring two pointer to reference the allocated memory for 2d array ex: str[10][10]
    int top;
    int end;
}stack;

void initStack(stack* stack)
{
    stack->top = 0; 
    stack->end = 0;
    stack->str = malloc(sizeof(char*) * 10); // allocate memory
}

void enStack(stack* Stack, char* str)
{
    Stack->str[Stack->end] = malloc(sizeof(char) * 10); // allocating memory to store string pointing to already alocated memory ex: str[10][10]
    strcpy(Stack->str[Stack->end++], str); // copy string content to stack
}

void deStack(stack* Stack)
{
    if (Stack->top == Stack->end)
    {
        printf("End of stack\n");
        return;
    }
    printf("Destack: %s\n", Stack->str[Stack->top]); // pop string content from to stack
    free(Stack->str[Stack->top++]); // free empty memory after pop operation
}

int main()
{
    stack Stack;

    initStack(&Stack);

    enStack(&Stack, "Hello");
    enStack(&Stack, "World");
    enStack(&Stack, "Bye!");

    deStack(&Stack);
    deStack(&Stack);
    deStack(&Stack);
    deStack(&Stack);

    return 0;
}
