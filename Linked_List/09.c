/*
9) Pairwise swap elements of a linked list. 
WTD: Swap every two adjacent nodes by adjusting their pointers. 
(e.g.: I/P: 1->2->3->4; O/P: 2->1->4->3)
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

void pairwiseSwap(node** head_ref)
{ 
    node* currentNode = *head_ref;
    node* nextNode = NULL;
    node* prevNode = NULL;

    while (currentNode != NULL && currentNode->next != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = nextNode->next;
        nextNode->next = currentNode;

        if (prevNode == NULL)
        {
            *head_ref = nextNode;
        }
        else
        {
            prevNode->next = nextNode;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }    
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
    pairwiseSwap(&head);
    display(head);

    return 0;
}