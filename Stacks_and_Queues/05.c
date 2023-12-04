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

typedef struct node // creating struct for list
{
    char data;
    struct node* next;
}Node;

typedef struct // creating struct to point node in the list
{
    Node* top;
}Stack;

Node* createNode(char data) // creating node
{
    Node* tempNode = (Node*)malloc(sizeof(Node));
    tempNode->data = data;
    tempNode->next = NULL;

    return tempNode;
}

void initStack(Stack** stack_ref)
{
    *stack_ref = (Stack*)malloc(sizeof(Stack)); // allocate memory for Stack struct
    (*stack_ref)->top = NULL; // initialize null to allocated memory
}

void push(Stack** stack_ref, char data)
{
    Stack* stack = *stack_ref;
    Node* temp = createNode(data); // create and copy new node to temp
    if (stack->top == NULL) // if stack is empty
    {
        stack->top = temp; 
    }
    else // if stack is not empty
    {
        temp->next = stack->top; // insert new node at end
        stack->top = temp; // move top pointer to inserted new node
    }
}

char pop(Stack** stack_ref)
{
    Stack* stack = *stack_ref;
    if (stack->top == NULL) // return if stack is empty
    {
        printf("Stack is empty\n");
        return 0;
    }
    
    char s = stack->top->data;
    Node* temp = stack->top; // create temp node poining top node
    stack->top = stack->top->next; // move top to next node
    free(temp); // release temp node

    return s;
}

int main()
{
    Stack* stack = NULL;
    initStack(&stack);
    char str[] = "{cmd1{cmd2}}";
    char* str_ptr = str;
    int depth = 0;

    while (*str_ptr != '\0') // iterating each char in string
    {
        if (*str_ptr == '{' || *str_ptr == '(' || *str_ptr == '[') // do push operation if open braces encountered
        {
            push(&stack, *str_ptr);
        }
        else if (*str_ptr == '}' || *str_ptr == ')' || *str_ptr == ']') // if close braces is encountered compare with braces in stack
        {
            char s = pop(&stack);

            if (*str_ptr == '}' && s == '{' || *str_ptr == ']' && s == '[' || *str_ptr == '(' && s == ')') // compare and increment depth if braces is correct
            {
                depth++;
            }
        }
        str_ptr++; // move to next char in the string
    }
    printf("Depth: %d",depth);

    return 0;
}
