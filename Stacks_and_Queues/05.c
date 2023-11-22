/*
5) Command Parser.  
WTD: Develop a command parser using a stack that can handle nested commands. The 
parser should be able to distinguish between different types of commands and their nesting 
levels. Implement a mechanism to return the depth of the nested commands for debugging 
or other purposes.   
(e.g: I/P: "{CMD1 {CMD2}}" ; O/P: Depth - 2)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node* next;
}Node;

typedef struct 
{
    Node* top;
}Stack;

Node* createNode(char data)
{
    Node* tempNode = (Node*)malloc(sizeof(Node));
    tempNode->data = data;
    tempNode->next = NULL;

    return tempNode;
}

void initStack(Stack** stack_ref)
{
    *stack_ref = (Stack*)malloc(sizeof(Stack));
    (*stack_ref)->top = NULL;
}

void push(Stack** stack_ref, char data)
{
    Stack* stack = *stack_ref;
    Node* temp = createNode(data);
    if (stack->top == NULL)
    {
        stack->top = temp;
    }
    else 
    {
        temp->next = stack->top;
        stack->top = temp;
    }
}

char pop(Stack** stack_ref)
{
    Stack* stack = *stack_ref;
    if (stack->top == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    
    char s = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    return s;
}

int main()
{
    Stack* stack = NULL;
    initStack(&stack);
    char str[] = "{cmd1{cmd2}}";
    char* str_ptr = str;
    int depth = 0;

    while (*str_ptr != '\0')
    {
        if (*str_ptr == '{' || *str_ptr == '(' || *str_ptr == '[')
        {
            push(&stack, *str_ptr);
        }
        else if (*str_ptr == '}' || *str_ptr == ')' || *str_ptr == ']')
        {
            char s = pop(&stack);

            if (*str_ptr == '}' && s == '{' || *str_ptr == ']' && s == '[' || *str_ptr == '(' && s == ')')
            {
                depth++;
            }
        }
        str_ptr++;
    }
    printf("Depth: %d",depth);

    return 0;
}