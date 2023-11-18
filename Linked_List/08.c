/*
8) Delete alternate nodes of a linked list. 
WTD: Traverse the list and remove every alternate node. 
(e.g.: I/P: 1->2->3->4; O/P: 1->3)
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

void deleteAlternateNode(node** head_ref)
{ 
    node* tempNode = *head_ref;
    node* delNode = NULL;
    
    while (tempNode != NULL && tempNode->next != NULL)
    {
        delNode = tempNode->next;
        tempNode->next = delNode->next;
        delNode->next = NULL;
        free(delNode);
        tempNode = tempNode->next;
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
    deleteAlternateNode(&head);
    display(head);

    return 0;
}