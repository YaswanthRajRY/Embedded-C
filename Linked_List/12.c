/*
12) Segregate even and odd nodes in a linked list. 
WTD: Use two pointers to rearrange nodes such that all even and odd elements are 
together. 
(e.g.: I/P: 1->2->3->4; O/P: 2->4->1->3)
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

int nodeLen(node* head_ref)
{
    int len = 0;
    while (head_ref != NULL)
    {
        head_ref = head_ref->next;
        len++;
    }
    return len;
}

void seperateEvenOdd(node** head_ref)
{
    node* evenNode_head = NULL;
    node* evenNode_tail = NULL;
    node* oddNode_head = NULL;
    node* oddNode_tail = NULL;
    node* current = *head_ref;

    while (current != NULL)
    {
        if (current->data % 2 == 0)
        {
            if (evenNode_head == NULL)
            {
                evenNode_head = current;
                evenNode_tail = evenNode_head;
            }
            else
            {
                evenNode_tail->next = current;
                evenNode_tail = current;
            }
        }
        else
        {
            if (oddNode_head == NULL)
            {
                oddNode_head = current;
                oddNode_tail = oddNode_head;
            }
            else
            {
                oddNode_tail->next = current;
                oddNode_tail = current;
            }
        }
        current = current->next;
    }
    
    if (evenNode_head != NULL)
    {
        evenNode_tail->next = oddNode_head;
        oddNode_tail->next = NULL;
        *head_ref = evenNode_head;
    }
    else
    {
        *head_ref = oddNode_head;
        oddNode_tail->next = NULL;
    }
}

int main()
{
    node* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    //insertNode(&head, 5);

    display(head);

    seperateEvenOdd(&head);

    printf("o/p: ");
    display(head);

    return 0;
}