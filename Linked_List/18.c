/*
18) Merge sort on a linked list. 
WTD: Implement the Merge Sort algorithm on a linked list, splitting the list into halves and 
merging them back in sorted order. 
(e.g.: I/P: 3->1->2; O/P: 1->2->3)
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

    if(*head_ref == NULL)
    {
        *head_ref = tempNode;
    }
    else
    {
        node* currentNode = *head_ref;
        while (currentNode != NULL && currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = tempNode;
    }
}

void display(node* head_ref)
{
    if (head_ref == NULL)
    {
        printf("NULL\n");
    }

    while (head_ref != NULL)
    {
        printf("%d-> ",head_ref->data);
        head_ref = head_ref->next;
    }
    printf("NULL\n");
}

void split(node* head, node** a, node** b)
{
    node* slow = head;
    node* fast = head->next->next;

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

node* sort(node* a, node* b)
{
    node* sorted = NULL;

    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    if (a->data <= b->data)
    {
        sorted = a;
        sorted->next = sort(a->next, b);
    }
    else
    {
        sorted = b;
        sorted->next = sort(a, b->next);
    }

    return sorted;
}

node* mergeandsort(node** head_ref)
{
    node* head = *head_ref;
    node* a = NULL;
    node* b = NULL;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    split(head, &a, &b);

    mergeandsort(&a);
    mergeandsort(&b);

    *head_ref = sort(a, b);
}

int main()
{
    node* head = NULL;
    
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);
    insertNode(&head, 5);
    insertNode(&head, 6);
    insertNode(&head, 4);

    display(head);

    node* result = mergeandsort(&head);

    display(result);

    return 0;
}