/* 
11) Stack-based Text Editor. 
WTD: Design a text editor that uses a stack to implement basic text editing features like 
undo and redo. Each operation should push the current state of the text onto the stack, 
allowing for easy rollback or re-application of changes.   
(e.g: I/P: Add "Hello", Undo, Add "Hi" ; O/P: "Hi") 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char* str;
    struct stack* next;
}Stack;

void push(Stack** stack, char* s)
{
    Stack* tempNode = (Stack*)malloc(sizeof(Stack));    // allocate memory for new node
    tempNode->str = (char*)malloc(sizeof(char) * strlen(s));    // allocatre memory for storing string
    strcpy(tempNode->str, s);   // copy string to tempNode
    tempNode->next = NULL;

    if ((*stack) == NULL)   // if stack is empty make it as first node
    {
        (*stack) = tempNode;
    }
    else
    {
        tempNode->next = (*stack);      // add tempNode at the front
        (*stack) = tempNode;        // move first node pointer to newly added node
    }
}

void pop(Stack** stack)
{
    if ((*stack) == NULL)   // terminate if stack is empty
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Stack* temp = (*stack);
        (*stack) = (*stack)->next;
        temp->next = NULL;
        free(temp);
    }
}

void displayStack(Stack* stack)     // display content in stack in reverse
{
    if (stack == NULL)
    {
        return;
    }
    displayStack(stack->next);      // recursion to print in reverse order

    printf("%s ",stack->str);
}

int main()
{
    Stack* stack = NULL;
    char data[100];
    int add,undo,sw;

    while (1)
    {
        printf("Press 1 to ADD / press 2 to UNDO\n");
        scanf("%d", &sw);

        switch (sw)
        {
        case 1:
            printf("ADD: ");
            scanf(" %[^\n]s", data);
            char* token = strtok(data, " ");
            while (token != NULL)
            {
                push(&stack, token);
                token = strtok(NULL, " ");
            }
            displayStack(stack);
            printf("\n\n");
            break;

        case 2:
            pop(&stack);
            printf("Undo: ");
            displayStack(stack);
            printf("\n\n");
            break;
        
        default:
            printf("Invalid entry\n\n");
            break;
        }
    }

    return 0;
}