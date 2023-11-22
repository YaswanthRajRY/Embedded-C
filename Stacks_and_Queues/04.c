/*
4) Expression Validator. 
WTD: Develop a stack-based mechanism to validate the correctness of arithmetic 
expressions by checking for balanced parentheses and proper operator placement.  
(e.g: I/P: "(a+b) * (c-d)" ; O/P: Valid Expression)
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

void initStack(Stack* stack)
{
    stack->top = NULL;
}

void push(Stack** stack_ref, char data)
{
    Stack* stack = *stack_ref;
    Node* temp = createNode(data);

    if(stack->top == NULL)
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

int checkExpression(Stack* stack,char* str)
{
    char* str_ptr = str;

    while (*str_ptr != '\0')
    {
        if (*str_ptr == '(' || *str_ptr == '[' || *str_ptr == '{')
        {
            push(&stack, *str_ptr);
        }
        else if (*str_ptr == ')' || *str_ptr == ']' || *str_ptr == '}')
        {
            char popedElement = pop(&stack);

            if (*str_ptr == ')' && popedElement != '(' || *str_ptr == ']' && popedElement != '[' || *str_ptr == '}' && popedElement != '{')
            {
                return 0;
            }
        }        
        else if(*str_ptr == '+' || *str_ptr == '-' || *str_ptr == '*' || *str_ptr == '/')
        {
            if (*(str_ptr + 1) == '+' || *(str_ptr + 1) == '-' || *(str_ptr + 1) == '*' || *(str_ptr + 1) == '/' || *(str_ptr + 1) == '\0')
            {
                return 0;
            }
            else if (*(str_ptr + 1) == ')' || *(str_ptr + 1) == ']' || *(str_ptr + 1) == '}' )
            {
                return 0;
            }
        }
        str_ptr++;
    }

    return 1;
}

int main()
{
    Stack stack;
    initStack(&stack);

    char str[] = "(a+b)*(c-d)";
    if (checkExpression(&stack, str))
    {
        printf("Valid expression\n");
    }
    else
    {
        printf("Not valid expression\n");
    }

    return 0;
}