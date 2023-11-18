/*
7) Move last element to the front of a given linked list. 
WTD: Find the last node and its previous node, change their pointers to move the last node 
to the front. 
(e.g.: I/P: 1->2->3->4; O/P: 4->1->2->3)
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

    if (*head_ref == NULL)
    {
        *head_ref = tempNode;
    }
    else
    {
        node* nodePtr = *head_ref;
        while (nodePtr != NULL && nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = tempNode;
    }
}

void display(node* head_ref)
{
    for (node* currentNode = head_ref; currentNode != NULL; currentNode = currentNode->next)
    {
        printf("%d->",currentNode->data);
    }
    printf("NULL\n");
}

void lastTofirst(node** head_ref)
{ 
    node* tempNode = *head_ref;
    node* lastNode = NULL;
    node* firstNode = *head_ref;
    
    while (tempNode != NULL && tempNode->next->next != NULL)
    {
        tempNode = tempNode->next;
    }
    lastNode = tempNode->next;
    tempNode->next = firstNode;
    lastNode->next = firstNode->next;
    firstNode->next = NULL;
    
    *head_ref = lastNode;
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
    lastTofirst(&head);
    display(head);

    return 0;
}