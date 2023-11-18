/*
25) Determine if a linked list is a palindrome. 
WTD: Use a slow and fast pointer to find the middle of the list. Reverse the second half and 
compare it with the first half to determine if the linked list is a palindrome. 
(e.g.: I/P: 1->2->2->1; O/P: True)
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

int palindrome(node* head_ref)
{
    node* slow = head_ref;
    node* fast = head_ref;
    node* slowPrev = NULL;
    node* middleNode = NULL; 

    if (fast == NULL || fast->next == NULL)
    {
        return 1;
    }

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slowPrev = slow;
        slow = slow->next;
    }

    if (fast != NULL)
    {
        middleNode = slow;
        slow = slow->next;
    }
    slowPrev->next = NULL;
    node* secondHalf = reverse(slow);
    fast = secondHalf;
    node* firstHalf = head_ref;

    while (firstHalf != NULL || secondHalf != NULL)
    {
        if (firstHalf->data != secondHalf->data)
        {
            reverse(fast);
            if (middleNode != NULL)
            {
                middleNode->next = slow;
                slow = middleNode;
            }
            slowPrev->next = slow;
            return 0;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    reverse(fast);
    if (middleNode != NULL)
    {
        middleNode->next = slow;
        slow = middleNode;
    }
    slowPrev->next = slow;
    return 1;
}

int main()
{
    node* head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);   

    display(head);

    int b = palindrome(head);

    if (b)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }

    display(head);

    return 0;
}