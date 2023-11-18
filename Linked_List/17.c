/*
17) Clone a linked list with next and random pointer. 
WTD: Create a deep copy of the linked list including the random pointers using a hash 
table to map original nodes to their copies. 
(e.g.: I/P: 1->2->3 (random pointers set randomly); O/P: Cloned list with same structure 
and random pointers)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node* next;
    struct Node* random;
}node;

node* createNode(int data)
{
    node* tempNode = (node*)malloc(sizeof(node));
    tempNode->data = data;
    tempNode->next = NULL;
    tempNode->random = NULL;

    return tempNode;
}

void display(node* head_ref)
{
    if(head_ref == NULL)
    {
        printf("NULL\n");
        return;
    }
    while (head_ref != NULL)
    {
        printf("%d(%d)-> ",head_ref->data, (head_ref->random != NULL) ? head_ref->random->data : -1);
        head_ref = head_ref->next;
    }

    printf("NULL\n");
}

node* duplicateNode(node* head_ref)
{
    node* normalPtr = head_ref;
    node* randomPtr = head_ref;
    node* duplicateNode = NULL;
    node *tail = NULL;

    while (normalPtr != NULL)
    {
        node* tempNode = createNode(normalPtr->data);
        if (duplicateNode == NULL)
        {
            duplicateNode = tempNode;
            tail = duplicateNode;
        }
        else
        {
            tail->next = tempNode;
            tail = tempNode;
        }
        
        normalPtr = normalPtr->next;
    }

    tail = duplicateNode;
    while (randomPtr != NULL)
    {
        tail->random = randomPtr->random;
        tail = tail->next;
        randomPtr = randomPtr->next;
    }
    return duplicateNode;
}

int main()
{
    node* head = NULL;
    node* node1 = createNode(1);    
    node* node2 = createNode(2);
    node* node3 = createNode(3);
    node* node4 = createNode(4);
    node* node5 = createNode(5);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1->random = node3;
    node3->random = node4;
    node4->random = node2;
    node5->random = node1;

    display(head);

    node* clone = duplicateNode(head);

    display(clone);

    return 0;
}