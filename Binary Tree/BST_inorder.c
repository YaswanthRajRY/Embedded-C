#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left, *right;
}node;

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

void inorder(node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
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

    inorder(root);

    printf("\n");

    return 0;
}