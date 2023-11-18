/*
19) Detect and remove loop in a linked list. 
WTD: Use Floyd's algorithm to detect the loop and then remove it by setting the next 
pointer of the last node in the loop to NULL. 
(e.g.: I/P: 1->2->3 (3 points back to 1); O/P: 1->2->3)
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
    tempNode->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = tempNode;
        tempNode->next = *head_ref;
    }
    else
    {
        node* currentNode = *head_ref;
        while (currentNode != NULL && currentNode->next != *head_ref)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = tempNode;
        tempNode->next = *head_ref;
    }
}

void display(node* head_ref)
{
    if (head_ref == NULL)
    {
        printf("NULL\n");
    }

    while (head_ref != NULL)
    {
        printf("%d-> ",head_ref->data);
        head_ref = head_ref->next;
    }
    printf("NULL\n");
}

void removeLoop(node** head_ref)
{
    node* slowPtr = *head_ref;
    node* fastPtr = slowPtr->next->next;

    while (slowPtr != fastPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    printf("Linked list is circular\n");

    slowPtr = *head_ref;
    while (fastPtr->next != slowPtr)
    {
        fastPtr = fastPtr->next;
    }
    fastPtr->next = NULL;
}

int main()
{
    node* head = NULL;
    
    for (int i=1; i<=5; i++)
    {
        insertNode(&head, i);
    }

    removeLoop(&head);

    display(head);

    return 0;
}