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
    Stack->str = malloc(sizeof(char) * 10); // allocating dynamic memory size of required stack size 
}

void push(stack* Stack, char str)
{
    Stack->str[Stack->top] = str; // pushing char in stack
    Stack->top++; // increment to next memory location to store next char
}

char pop(stack* Stack)
{
    return Stack->str[--Stack->top]; // removing char out from the stack 
}

int main()
{
    stack Stack;

    initStack(&Stack);

    char s[] = "{{()}}";
    char* s_ptr = s;
    int depth = 0;

    while (*s_ptr != '\0') // iterating each char in given string untill null char
    {
        if (*s_ptr == '(' || *s_ptr == '[' || *s_ptr == '{') // if any open braces do push operation
        {
            push(&Stack,*s_ptr);
        }
        else if (*s_ptr == ')' || *s_ptr == '}'|| *s_ptr == ']') // if encounters close braces symbol do pop operation
        {
            char top = pop(&Stack); // store poped braces symbol in top
            if (*s_ptr == ')' && top == '(' || *s_ptr == '}' && top == '{' || *s_ptr == ']' && top == '[') // if stored symbol is belongs to encountered close braces
            {
                depth++; // increment depth value
            }
        }
        s_ptr++; // move to next char in the string
    }

    printf("Depth: %d",depth);

    return 0;
}
