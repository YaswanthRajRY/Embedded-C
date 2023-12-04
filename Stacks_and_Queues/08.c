/*
8) Function Call Logger. 
WTD:  Implement a stack that logs function calls during the runtime of a program. This 
stack should allow for backtracking, enabling the user to trace the sequence of function calls 
and understand the flow of execution.   
(e.g: I/P: Call FuncA, Call FuncB, Return ; O/P: Current function - FuncA)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct
{
    const char* data[MAX_SIZE];
    int top;
}Stack;

Stack stack; // create global obj

void initStack()
{
    stack.top = -1;
}

void push(const char* funcName)
{
    if (stack.top == MAX_SIZE)
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        stack.data[++stack.top] = funcName;
    }
}

void pop()
{
    if (stack.top < 0)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("%s\n",stack.data[stack.top--]);
    }
}

void funcA();
void funcB();
void funcB();

int main()
{
    initStack();

    funcA();
    funcB();

    return 0;
}

void funcA()
{
    push(__FUNCTION__); // __FUNCTION__ will give function name as string

    pop();
}

void funcC()
{
    push(__FUNCTION__);

    pop();
}

void funcB()
{
    push(__FUNCTION__);
    funcC();
    pop();
}
