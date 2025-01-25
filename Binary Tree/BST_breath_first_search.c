#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left, *right;
}node;

typedef struct queue
{
    node* root;
    struct queue* next;
}queue;

void enqueue(queue** q, node* root)
{
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->root = root;
    temp->next = NULL;
    if (*q == NULL)
    {
        *q = temp;
    }
    else
    {
        queue* tail = *q;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = temp;
    }
}

node* dequeue(queue** q)
{
    if (*q == NULL)
    {
        return NULL;
    }
    queue* temp = *q;
    node* returnValue = temp->root; 
    *q = temp->next;
    free(temp);

    return returnValue;
}

int isEmpty(queue** q)
{
    if (*q == NULL)
    {
        return 1;
    }    
    else
    {
        return 0;
    }
}

node* createNode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node* insertNode(node** root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    
    if (data < (*root)->data)
    {
        (*root)->left = insertNode(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        (*root)->right = insertNode(&(*root)->right, data);
    }

    return *root;
}

void BFS(node* root)
{
    queue* myQueue = NULL;
    enqueue(&myQueue, root);

    while (!isEmpty(&myQueue))
    {
        node* temp = dequeue(&myQueue);
        printf("%d", temp->data);

        if (temp->left != NULL)
        {
            enqueue(&myQueue, temp->left);
        }
        if (temp->right != NULL)
        {
            enqueue(&myQueue, temp->right);
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

    BFS(root);
    printf("\n");

    return 0;
}