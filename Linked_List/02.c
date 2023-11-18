/*
2) Find the length of a singly linked list. 
WTD: Traverse the list from head to tail, incrementing a counter to find its length. 
(e.g.: I/P: 1->2->3->4; O/P: 4) 
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

void findNodelen(node** head_ref)
{
    int count=0;
    for (node* currentNode = *head_ref; currentNode != NULL; currentNode = currentNode->next)
    {
        count++;
    }
    printf("%d",count);
}

int main()
{
    node* head = NULL;
    int i;
    for (i=1; i<=5; i++)
    {
        insertNode(&head,i);
    }

    display(head);
    findNodelen(&head);

    return 0;
}