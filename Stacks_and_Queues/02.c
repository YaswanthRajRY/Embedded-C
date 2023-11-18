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
    char** str;
    int top;
    int end;
}stack;

void initStack(stack* stack)
{
    stack->top = 0; 
    stack->end = 0;
    stack->str = malloc(sizeof(char*) * 10);
}

void enStack(stack* Stack, char* str)
{
    Stack->str[Stack->end] = malloc(sizeof(char) * 10);
    strcpy(Stack->str[Stack->end++], str);
}

void deStack(stack* Stack)
{
    if (Stack->top == Stack->end)
    {
        printf("End of stack\n");
        return;
    }
    printf("Destack: %s\n", Stack->str[Stack->top]);
    free(Stack->str[Stack->top++]);
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