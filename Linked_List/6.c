/*
6) Find nth node from end of a singly linked list. 
WTD: Use two pointers, move one n nodes ahead, then move both until the first one 
reaches the end. 
(e.g.: I/P: 1->2->3->4 (n=2); O/P: 3)
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

void nNode(node** head_ref, int data)
{ 
    node* ptr_1 = *head_ref;
    node* ptr_2 = *head_ref;
    
    for(int i=0; i<data; i++)
    {
        ptr_1 = ptr_1->next;
    }

    while(ptr_1 != NULL)
    {
        ptr_1 = ptr_1->next;
        ptr_2 = ptr_2->next;
    }

    printf("%d",ptr_2->data);
}

int main()
{
    node* head = NULL;
    int data;
    printf("n: ");
    scanf("%d",&data);
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);

    display(head);
    nNode(&head, data);

    return 0;
}