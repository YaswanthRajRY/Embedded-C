/*
11) Intersection point of two linked lists. 
WTD: Use two pointers, one for each list, and traverse to find the intersection point. 
(e.g.: I/P: 1->2->3 & 4->5->3; O/P: 3)
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

void intersectNode(node** head_ref1, node** head_ref2, int pos)
{
    node* intersectPoint = *head_ref1;
    node* lastNode = *head_ref2;

    while (intersectPoint != NULL && pos > 0)
    {
        intersectPoint = intersectPoint->next;
        pos--;
    }

    while (lastNode != NULL && lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = intersectPoint;
}

void findIntersectionPoint(node* head_ref1, node* head_ref2)
{
    while (head_ref2 != NULL)
    {
        node* temp_head1 = head_ref1;
        while (temp_head1 != NULL)
        {
            if (temp_head1 == head_ref2)
            {
                printf("%d",temp_head1->data);
                return;
            }
            temp_head1 = temp_head1->next;
        }
        head_ref2 = head_ref2->next;
    }
}

void display(node* head_ref)
{
    if (head_ref == NULL)
    {
        return;
    }

    while (head_ref != NULL)
    {
        printf("%d->",head_ref->data);
        head_ref = head_ref->next;
    }
    printf("NULL\n");
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    int pos = 2;

    insertNode(&head1,1);
    insertNode(&head1,2);
    insertNode(&head1,3);
    insertNode(&head1,4);
    insertNode(&head1,5);

    insertNode(&head2,4);
    insertNode(&head2,5);

    intersectNode(&head1, &head2, pos);

    display(head1);
    display(head2);

    findIntersectionPoint(head1, head2);

    return 0;
}
