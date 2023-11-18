/*
22) Remove all nodes in a linked list that have a specific value. 
WTD: Traverse the linked list and remove any node that has a value matching the specified 
value. Make sure to properly update the next pointers and free any removed nodes. 
(e.g.: I/P: 1->2->6->3->4->5->6, Value to Remove: 6; O/P: 1->2->3->4->5)
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

void removeNode(node** head_ref, int num)
{
    node* current = *head_ref;
    node* prev = NULL;

    while (current != NULL)
    {
        if (current->data == num)
        {
            if (prev == NULL)
            {
                *head_ref = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            node* temp = current;
            current = current->next;
            free(temp);
        }    
        else
        {
            prev = current;
            current = current->next;
        }   
    }
}

int main()
{
    node* head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 2);

    display(head);

    removeNode(&head, 2);

    display(head);

    return 0;
}