/*
4) Expression Validator. 
WTD: Develop a stack-based mechanism to validate the correctness of arithmetic 
expressions by checking for balanced parentheses and proper operator placement.  
(e.g: I/P: "(a+b) * (c-d)" ; O/P: Valid Expression)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node // create struct for list
{
    char data;
    struct node* next;
}Node;

typedef struct // create struct for pointing top node 
{
    Node* top;
}Stack;

Node* createNode(char data) // create node
{
    Node* tempNode = (Node*)malloc(sizeof(Node)); 
    tempNode->data = data;
    tempNode->next = NULL;

    return tempNode; // return node
}

void initStack(Stack* stack) 
{
    stack->top = NULL;
}

void push(Stack** stack_ref, char data)
{
    Stack* stack = *stack_ref;
    Node* temp = createNode(data); // create and store new node to temp

    if(stack->top == NULL) // if stack is empty
    {
        stack->top = temp; 
    }
    else // if stack already has content
    {
        temp->next = stack->top; // connect new node to top
        stack->top = temp; // move top pointer to newly connected node temp
    }
}

char pop(Stack** stack_ref)
{
    Stack* stack = *stack_ref;
    if (stack->top == NULL) // if stack is empty return 
    {
        printf("Stack is empty\n");
        return 0;
    }

    char s = stack->top->data; 
    Node* temp = stack->top; // create new pointer points top
    stack->top = stack->top->next; // move top pointer to next node
    free(temp); // free memory points to new pointer temp
    return s;
}

int checkExpression(Stack* stack,char* str)
{
    char* str_ptr = str;

    while (*str_ptr != '\0') // iterating each char in the string untill null
    {
        if (*str_ptr == '(' || *str_ptr == '[' || *str_ptr == '{') // do push operation if open braces encountered
        {
            push(&stack, *str_ptr);
        }
        else if (*str_ptr == ')' || *str_ptr == ']' || *str_ptr == '}') // if close brace symbol encountered
        {
            char popedElement = pop(&stack); // store poped data in temporary cariable

            if (*str_ptr == ')' && popedElement != '(' || *str_ptr == ']' && popedElement != '[' || *str_ptr == '}' && popedElement != '{') 
            {
                return 0; // return if poped symbol is not same type of encountered close braces.
            }
        }        
        else if(*str_ptr == '+' || *str_ptr == '-' || *str_ptr == '*' || *str_ptr == '/') // if arithmatic operator encountered 
        {
            if (*(str_ptr + 1) == '+' || *(str_ptr + 1) == '-' || *(str_ptr + 1) == '*' || *(str_ptr + 1) == '/' || *(str_ptr + 1) == '\0')
            {
                return 0; // return if 2 consecutive arithmatic operator is found
            }
            else if (*(str_ptr + 1) == ')' || *(str_ptr + 1) == ']' || *(str_ptr + 1) == '}' )
            {
                return 0; // return if arithmatic operator is end of num ex: 1- (which is wrong)
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
