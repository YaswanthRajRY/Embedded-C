/*
10) Check if a given linked list contains a cycle and what would be the starting node? 
WTD: Use Floyd’s cycle-finding algorithm to detect the cycle and then find its starting 
node. 
(e.g.: I/P: 1->2->3 (3 points back to 1); O/P: True)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node;

void insertNode(node** head_ref, int data)
{
    node* tempNode = (node*)malloc(sizeof(node));
    tempNode->data = data;

    if (*head_ref == NULL)
    {
        tempNode->next = tempNode;
        *head_ref = tempNode;
    }
    else
    {
        node* lastNode = *head_ref;
        while (lastNode->next != *head_ref)
        {
            lastNode = lastNode->next;
        }
        
        lastNode->next = tempNode;
        tempNode->next = *head_ref;
    }
}

void display(node* head_ref)
{
    if (head_ref == NULL)
    {
        printf("NULL");
    }

    node* currentNode = head_ref;
    do 
    {
        printf("%d->",currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head_ref);
}

void floydCycle(node** head_ref)
{ 
    node* slowPtr = *head_ref;
    node* fastPtr = *head_ref;

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        
        if (fastPtr == slowPtr)
        {
            printf("\nTrue\n");
            break;
        }
        else if(fastPtr->next == NULL)
        {
            printf("False");
            return;
        }    
    }    

    fastPtr = *head_ref;
    printf("starting node => %d",fastPtr->data);
}

int main()
{
    node* head = NULL;

    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);

    display(head);
    floydCycle(&head);

    return 0;
}