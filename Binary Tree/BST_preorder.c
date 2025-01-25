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
    node* tempRoot = *root;
    if (tempRoot == NULL)
    {
        *root = createNode(data);
        return *root;
    }
    else
    {
        if (data < tempRoot->data)
        {
            tempRoot->left = insertNode(&tempRoot->left, data);
        }
        else if (data > tempRoot->data)
        {
            tempRoot->right = insertNode(&tempRoot->right, data);
        }
    }
    return tempRoot;
}

void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
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