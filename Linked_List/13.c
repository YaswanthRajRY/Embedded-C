/*
13) Merge two sorted linked lists. 
WTD: Use a temporary dummy node to hold the sorted list, compare each node and attach 
the smaller one to the dummy. 
(e.g.: I/P: 1->3->5 & 2->4->6; O/P: 1->2->3->4->5->6)
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
        node* lastNode = *head_ref;
        while (lastNode != NULL && lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = tempNode;
    }
}

void display(node* head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void mergeTwonode(node* head_ref1, node* head_ref2)
{
    node* dummyNode_head = NULL;
    node* dummyNode_tail = NULL;
    node* head1 = head_ref1;
    node* head2 = head_ref2;
    
    while (head1 != NULL && head2 != NULL)
    {
        int data1 = (head1 != NULL) ? head1->data : 0;
        int data2 = (head2 != NULL) ? head2->data : 0;

        if (data1 < data2)
        {
            if (dummyNode_head == NULL)
            {
                dummyNode_head = head1;
                dummyNode_tail = dummyNode_head;
            }
            else
            {
                dummyNode_tail->next = head1;
                dummyNode_tail = head1;
            }
            if (head1 != NULL) head1 = head1->next;
        }
        else
        {
            if (dummyNode_head == NULL)
            {
                dummyNode_head = head2;
                dummyNode_tail = dummyNode_head;
            }
            else
            {
                dummyNode_tail->next = head2;
                dummyNode_tail = head2;
            }
            if (head2 != NULL) head2 = head2->next;
        }
    }
    if (head1 != NULL)
    {
        dummyNode_tail->next = head1;
    }
    else
    {
        dummyNode_tail->next = head2;
    }
    
    printf("o/p: ");
    display(dummyNode_head);
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    insertNode(&head1, 1);
    insertNode(&head1, 3);
    insertNode(&head1, 5);

    insertNode(&head2, 2);
    insertNode(&head2, 4);
    insertNode(&head2, 6);
    

    display(head1);
    display(head2);

    mergeTwonode(head1, head2);

    return 0;
}