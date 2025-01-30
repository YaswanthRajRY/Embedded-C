/*
18. Design a program that finds the length of a linked list using double pointers. 
WTD: Use a double pointer (or two pointers) technique. Move one pointer twice as fast as 
the other. When the faster one reaches the end, the slower one will be halfway. 
 
(e.g.: I/P:1->2->3->4->5 ,O/P:5 )
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list* next;
}Node;

void createNode(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }
}

void display(Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int findListLength(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    int len = 0;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        len++;
    }

    if (fast != NULL)
    {
        len = 2 * len + 1;
    }
    else
    {
        len = 2 * len;
    }

    return len;
}

int main()
{
    Node* head = NULL;

    createNode(&head, 1);
    createNode(&head, 2);
    createNode(&head, 3);
    createNode(&head, 4);
    createNode(&head, 5);

    int res = findListLength(head);

    printf("%d",  res);

    return 0;
}