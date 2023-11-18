/*
1) Find Middle element of a singly linked list in one pass. 
WTD: Use two pointers, one moving twice as fast as the other, to find the middle element 
in a single pass. 
(e.g.: I/P: 1->2->3->4->5; O/P: 3)
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
        node* temp = *head_ref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = tempNode;
    }
}

void displayNode(node* head_ref)
{
    node* temp = head_ref;

    while (temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Null\n");
    }
}

void middleNode(node** head_ref)
{
    node* ptr_1 = *head_ref;
    node* ptr_2 = *head_ref;

    while (ptr_2 != NULL && ptr_2->next != NULL)
    {
        ptr_1 = ptr_1->next;
        ptr_2 = ptr_2->next->next;
    }
    printf("%d\n",ptr_1->data);
}

int main()
{
    node* head = NULL;
    int a;

    for (int i=0; i<5; i++)
    {
        scanf("%d",&a);
        insertNode(&head, a);
    }

    displayNode(head);

    middleNode(&head);

    return 0;
}