/*
5) Remove duplicate nodes in an unsorted linked list. 
WTD: Use a hash table to record the occurrence of each node while traversing the list to 
remove duplicates. 
(e.g.: I/P: 1->2->2->3; O/P: 1->2->3)
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
        node* nodePtr = *head_ref;
        while (nodePtr != NULL && nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = tempNode;
    }
}

void display(node* head_ref)
{
    for (node* currentNode = head_ref; currentNode != NULL; currentNode = currentNode->next)
    {
        printf("%d->",currentNode->data);
    }
    printf("NULL\n");
}

void deleteDuplicae(node** head_ref)
{ 
    int hashTable[10] = {0};
    node* p = *head_ref;
    node* q = NULL;

    while (p != NULL)
    { 
        int data = p->data;

        if (hashTable[data] == 0)
        {
            hashTable[data] = 1;
            q = p;
            p = p->next;
        }
        else
        {
            q->next = p->next;
            free(p);
            p = q;
            p = p->next;
        }
    }

}

int main()
{
    node* head = NULL;
    int i;
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,1);

    display(head);
    deleteDuplicae(&head);
    display(head);

    return 0;
}