/*
4) Reverse a singly linked list without recursion. 
WTD: Use iterative method to reverse the next pointers of each node. 
(e.g.: I/P: 1->2->3; O/P: 3->2->1) 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node;

node* head = NULL;

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

void reverseNode(node* p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverseNode(p->next);
    node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{
    int i;
    for (i=1; i<=5; i++)
    {
        insertNode(&head,i);
    }

    display(head);
    reverseNode(head);
    display(head);

    return 0;
}