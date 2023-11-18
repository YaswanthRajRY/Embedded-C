/*
20) Flatten a multi-level linked list. 
WTD: Use a stack or recursion to flatten the list so that all nodes are at the same level. 
(e.g.: I/P: 1->2->3 (2 has child 4->5); O/P: 1->2->4->5->3)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* c_next;
}node;

void insertNode(node** head_ref, int data)
{
    node* tempNode = (node*)malloc(sizeof(node));
    tempNode->data = data;
    tempNode->next = NULL;
    tempNode->c_next = NULL;

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

void insertChildnode(node** head_ref, int data)
{
    node* tempNode = (node*)malloc(sizeof(node));
    tempNode->data = data;
    tempNode->c_next = NULL;
    tempNode->next = NULL;

    node* current = *head_ref;
    while (current != NULL && current->next != NULL)
    {
        current = current->next;
    }

    if (current->c_next == NULL)
    {
        current->c_next = tempNode;
    }
    else
    {
        while (current != NULL && current->c_next != NULL)
        {
            current = current->c_next;
        }
        current->next = tempNode;
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

void displayChild(node* head_ref)
{
    if (head_ref == NULL)
    {
        printf("NULL\n");
    }

    while (head_ref != NULL)
    {
        if (head_ref->c_next != NULL)
        {
            node* child = head_ref->c_next;
            while (child != NULL)
            {
                printf("%d-> ",child->data);
                child = child->next;
            }
            printf("NULL\n");
        }
        head_ref = head_ref->next;
    }
}


void flattern(node** head_ref)
{
    node* current = *head_ref;

    while (current != NULL && current->next != NULL)
    {
        if (current->c_next != NULL)
        {
            node* temp = current->next;
            node* childNode = current->c_next;
            current->c_next = NULL;
            current->next = childNode;

            while (childNode->next != NULL)
            {
                childNode = childNode->next;
            }
            childNode->next = temp;
            current = childNode;
        }
        current = current->next;
    }

}

int main()
{
    node* head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertChildnode(&head, 4);
    insertChildnode(&head, 5);
    insertNode(&head, 3);

    display(head);
    displayChild(head);

    flattern(&head);

    display(head);
    displayChild(head);

    return 0;
}