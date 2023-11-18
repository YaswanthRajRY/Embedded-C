/*
15) Find sum of two linked list using stack. 
WTD: Use two stacks to hold the numbers from each list, then pop and sum them, storing 
the result in a new list. 
(e.g.: I/P: 2->4 & 5->6 (24 + 56); O/P: 8->0)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node
{
    int data;
    struct Node* next;
}node;

struct stack
{
    int arr[MAX_SIZE];
    int pointer;
};

void init_stack(struct stack* s)
{
    s->pointer = -1;
}

int pop(struct stack* s)
{
    if (s->pointer < 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->pointer--];
}

void push(struct stack* s, int data)
{
    if (s->pointer == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->pointer] = data;
}

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

int nodeLen(node* head_ref)
{
    int count = 0;
    while (head_ref != NULL)
    {
        head_ref = head_ref->next;
        count++;
    }

    return count;
}

node* addZero(node* head_ref)
{
    node* tempNode = (node*)malloc(sizeof(node));
    tempNode->data = 0;
    tempNode->next = head_ref;
    head_ref = tempNode;
    return head_ref;
}

node* addTwonodes(node* head_ref1, node* head_ref2)
{    
    struct stack s1;
    struct stack s2;
    node* h1 = head_ref1;
    node* h2 = head_ref2;
    int len1 = nodeLen(h1);
    int len2 = nodeLen(h2);
    node* addList = NULL;

    if (len1 != len2)
    {
        if (len1 > len2)
        {
            for (int i=0; i<len1-len2; i++)
            {
                h2 = addZero(h2);
            }
        }
        else
        {
            for (int i=0; i<len2-len1; i++)
            {
                h1 = addZero(h1);
            }
        }
    }

    init_stack(&s1);
    init_stack(&s2);

    while (h1 != NULL || h2 != NULL)
    {
        int d1 = (h1 != NULL) ? h1->data : 0;
        int d2 = (h2 != NULL) ? h2->data : 0;

        push(&s1, d1);
        push(&s2, d2);

        if (h1 != NULL) h1 = h1->next;
        if (h2 != NULL) h2 = h2->next;
    }

    int carry = 0;
    while (s1.pointer >= 0 || s2.pointer >= 0)
    {
        int d1 = pop(&s1);
        int d2 = pop(&s2);

        int sum = d1 + d2 + carry;

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
        tempNode->next = addList;
        addList = tempNode;
    }
    if (carry == 1)
    {
        node* tempNode = (node*)malloc(sizeof(node));
        tempNode->data = carry;
        tempNode->next = addList;
        addList = tempNode;
    }
    while(h1 != NULL)
    {
        node* temp = addList;
    }
    return addList;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    insertNode(&head1, 1);
    insertNode(&head1, 9);
    insertNode(&head1, 9);

    insertNode(&head2, 1);
    insertNode(&head2, 6);    

    display(head1);
    display(head2);

    node* res = addTwonodes(head1, head2);
    printf("o/p: ");
    display(res);

    return 0;
}