/*
3) Nested Statement Counter. 
WTD: Use a stack to simulate the nested structure of programming constructs like loops or 
if-statements, and return their depth.   
(e.g: I/P: { { } } ; O/P: Depth - 2) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char* str;
    int top;
}stack;

void initStack(stack* Stack)
{
    Stack->top = 0; 
    Stack->str = malloc(sizeof(char) * 10);
}

void push(stack* Stack, char str)
{
    Stack->str[Stack->top] = str;
    Stack->top++;
}

char pop(stack* Stack)
{
    return Stack->str[--Stack->top];
}

int main()
{
    stack Stack;

    initStack(&Stack);

    char s[] = "{cmd{cmd()}}";
    char* s_ptr = s;
    int depth = 0;

    while (*s_ptr != '\0')
    {
        if (*s_ptr == '(' || *s_ptr == '[' || *s_ptr == '{')
        {
            push(&Stack,*s_ptr);
        }
        else if (*s_ptr == ')' || *s_ptr == '}'|| *s_ptr == ']')
        {
            char top = pop(&Stack); 
            if (*s_ptr == ')' && top == '(' || *s_ptr == '}' && top == '{' || *s_ptr == ']' && top == '[') 
            {
                depth++;
            }
        }
        s_ptr++;
    }

    printf("Depth: %d",depth);

    return 0;
}