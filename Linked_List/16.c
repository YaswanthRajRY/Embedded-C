/*
16) Compare two strings represented as linked lists. 
WTD: Traverse both lists, comparing each node's value. If they are equal throughout, the 
lists are equal. 
(e.g.: I/P: 'a'->'b'->'c' & 'a'->'b'->'c'; O/P: Equal)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node* next;
}node;

void insertNode(node** head_ref, char data)
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
        node* nextNode = *head_ref;

        while(nextNode != NULL && nextNode->next != NULL)
        {
            nextNode = nextNode->next;
        }
        nextNode->next = tempNode;
    }
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
        printf("%c-> ",head_ref->data);
        head_ref = head_ref->next;
    }

    printf("NULL\n");
}

int nodeLength(node* head_ref)
{
    while(head_ref == NULL)
    {
        return 0;
    }
    
    int count=0;
    while (head_ref != NULL)
    {
        head_ref = head_ref->next;
        count++;
    }

    return count;
}

void compareLinklist(node* node1, node* node2)
{
    int l1 = nodeLength(node1);
    int l2 = nodeLength(node2);

    if (l1 != l2)
    {
        printf("Not Equal\n");
        return;
    }

    while (node1 != NULL || node2 != NULL)
    {
        if (node1->data != node2->data)
        {
            printf("Not Equal\n");
            return;
        }

        node1 = node1->next;
        node2 = node2->next;
    }

    printf("Equal\n");
}


int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    insertNode(&head1,'a');
    insertNode(&head1,'b');
    insertNode(&head1,'c');

    insertNode(&head2,'a');
    insertNode(&head2,'b');
    //insertNode(&head2,'c');

    display(head1);
    display(head2);

    compareLinklist(head1, head2);

    return 0;
}