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
    stack->str = malloc(sizeof(char*) * 10);     // allocate memory for struct
}

void push(stack* Stack, char* str)
{
    Stack->str[Stack->end] = malloc(sizeof(char) * 10);    // allocate memory to store string 
    strcpy(Stack->str[Stack->end++], str);     // Copy string to stack and increment the stack pointer
}

void pop(stack* Stack)
{
    if (Stack->top == Stack->end)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("pop: %s\n", Stack->str[Stack->top]); 
    free(Stack->str[Stack->top++]);     // free memory of poped string from the stack
}

int main()
{
    stack Stack;

    initStack(&Stack);

    push(&Stack, "Hello");
    push(&Stack, "World");
    push(&Stack, "Bye!");

    pop(&Stack);
    pop(&Stack);
    pop(&Stack);
    pop(&Stack);

    return 0;
}
