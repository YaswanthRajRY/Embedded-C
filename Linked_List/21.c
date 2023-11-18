/*
21) Partition a linked list around a given value. 
WTD: Traverse the linked list, creating two separate lists - one for values less than the 
partition value and another for values greater than or equal to the partition value. Finally, 
merge these lists. 
(e.g.: I/P: 1->4->3->2->5->2, Partition Value: 3; O/P: 1->2->2->4->3->5)
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

node* partition(node* head_ref, int num)
{
    node* lower = NULL;
    node* upper = NULL;
    node* current = head_ref;

    if (current == NULL || current->next == NULL)
    {
        return current;
    }

    while (current != NULL)
    {
        if (current->data < num)
        {
            insertNode(&lower, current->data);
        }
        else if (current->data >= num)
        {
            insertNode(&upper, current->data);
        }
        current = current->next;
    }

    node* res = merge(upper, lower);

    return res;
}

node* merge(node* upper, node* lower)
{
    node* temp = lower;

    while (temp->next != NULL && temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = upper;

    return lower;
}

int main()
{
    node* head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 4);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 5);
    insertNode(&head, 2);

    display(head);

    node* res = partition(head, 3);

    display(res);

    return 0;
}