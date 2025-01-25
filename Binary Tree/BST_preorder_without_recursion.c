#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left, *right;
}node;

typedef struct stack
{
    struct node* data;
    struct stack* next;
}stack;

node* createNode(int);
node* insertNode(node**, int);
void push(stack**, node*);
node* pop(stack**);
int isEmpty(stack**);

node* createNode(int data)
{
    node* tempNode = (node*)malloc(sizeof(node));
    tempNode->data = data;
    tempNode->left = tempNode->right = NULL;

    return tempNode;
}

node* insertNode(node** root, int data)
{
    node* tempNode = *root;
    if (tempNode == NULL)
    {
        *root = createNode(data);
        return *root;
    }

    if (data < tempNode->data)
    {
        tempNode->left = insertNode(&tempNode->left, data);
    }
    else if (data > tempNode->data)
    {
        tempNode->right = insertNode(&tempNode->right, data);
    }

    return tempNode;
}

int isEmpty(stack** top)
{
    if (*top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack** top, node* data)
{
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

node* pop(stack** top)
{
    stack* temp = *top;
    node* popValue = NULL;

    *top = temp->next;
    popValue = temp->data;
    free(temp);

    return popValue;
}

void preorder(node* root)
{
    node* temp = root;
    stack* s1 = NULL;
    int flag = 1;

    while(flag)
    {
        if (temp != NULL)
        {
            printf("%d", temp->data);
            push(&s1, temp);
            temp = temp->left;
        }
        else 
        {
            if (!isEmpty(&s1))
            {
                temp = pop(&s1);
                temp = temp->right;
            }
            else
            {
                flag = 0;
            }

        }
    }
}

int main()
{
    node* root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 2);
    insertNode(&root, 6);
    insertNode(&root, 1);
    insertNode(&root, 4);
    insertNode(&root, 9);
    insertNode(&root, 3);

    preorder(root);
   
    printf("\n");

    return 0;
}