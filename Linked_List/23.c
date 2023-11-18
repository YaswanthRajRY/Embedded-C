/*
23) Convert a binary number represented by a linked list to an integer. 
WTD: Traverse the linked list and convert the binary number represented by the linked list 
nodes to an integer. Use bit manipulation for the conversion. 
(e.g.: I/P: 1->0->1; O/P: 5)
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

node* reverse(node* head_ref)
{
    node* current = head_ref;
    node* next = NULL;
    node* prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;
    return head_ref;
}

int power(int num, int exp)
{
    int val = 1;

    while (exp)
    {
        val *= num;
        exp--; 
    }

    return val;
}

void binaryToint(node** head_ref)
{
    node* temp = *head_ref;
    node* reversedNode = reverse(temp);
    node* current = reversedNode;
    int i = 0;
    int integer = 0;

    while (current != NULL)
    {
        integer += ((current->data) * power(2, i));
        i++;
        current = current->next;
    }

    reverse(reversedNode);
    
    printf("%d",integer);
}

int main()
{
    node* head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 0);
    insertNode(&head, 1);

    display(head);

    binaryToint(&head);

    return 0;
}