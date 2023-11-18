/*
14) Add two numbers represented by linked lists. 
WTD: Traverse both lists, sum the corresponding nodes, and manage the carry. 
(e.g.: I/P: 2->4 & 5->6 (24 + 56); O/P: 8->0)
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

node* reverseNode(node* head_ref, node* prev)
{
    if (head_ref == NULL)
    {
        return prev;
    }
    node* next = head_ref->next;
    head_ref->next = prev;

    return reverseNode(next, head_ref);
}

node* addTwonodes(node* head_ref1, node* head_ref2)
{    
    node* addNode_h = NULL;
    int carry = 0;
    node* head1_r = head_ref1;
    node* head2_r = head_ref2;
    head1_r = reverseNode(head1_r, NULL);
    head2_r = reverseNode(head2_r, NULL);

    while (head1_r != NULL || head2_r != NULL)
    {
        int data_1 = (head1_r != NULL) ? head1_r->data : 0;
        int data_2 = (head2_r != NULL) ? head2_r->data : 0;

        int sum = data_1 + data_2 + carry;

        if (sum > 9)
        {
            sum %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        node* tempNode = (node*)malloc(sizeof(node));
        tempNode->data = sum;
        tempNode->next = NULL;

        if (addNode_h == NULL)
        {
            addNode_h = tempNode;
        }
        else
        {
            tempNode->next = addNode_h;
            addNode_h = tempNode; 
        }

        if (head1_r != NULL) head1_r = head1_r->next;
        if (head2_r != NULL) head2_r = head2_r->next;
    }

    if (carry > 0)
    {
        node* tempNode = (node*)malloc(sizeof(node));
        tempNode->data = carry;
        tempNode->next = addNode_h;
        addNode_h = tempNode;
    }

    while (head1_r != NULL)
    {
        node* temp = head1_r;
        head1_r = head1_r->next;
        free(temp);
    }

    while (head2_r != NULL)
    {
        node* temp = head2_r;
        head2_r = head2_r->next;
        free(temp);
    }
    
    return addNode_h;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    insertNode(&head1, 2);
    insertNode(&head1, 4);

    insertNode(&head2, 5);
    insertNode(&head2, 6);    

    display(head1);
    display(head2);

    node* res = addTwonodes(head1, head2);
    printf("o/p: ");
    display(res);

    return 0;
}