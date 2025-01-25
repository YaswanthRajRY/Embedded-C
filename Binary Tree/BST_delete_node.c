#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left, *right;
}node;

node* createNode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node* insertNode(node** root, int data)
{
    node* temp = *root;
    if (temp == NULL)
    {
        *root = createNode(data);
        return *root;
    }

    if (data < temp->data)
    {
        temp->left = insertNode(&temp->left, data);
    }
    else if (data > temp->data)
    {
        temp->right = insertNode(&temp->right, data);
    }

    return temp;
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

node* findMin(node* root)
{
    if (root->left == NULL)
    {
        return root;
    }
    findMin(root->left);
}

node* delete(node** root, int data)
{
    if (*root == NULL)
    {
        return *root;
    }
    else if (data < (*root)->data)
    {
        (*root)->left = delete(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        (*root)->right = delete(&(*root)->right, data);
    }
    else
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL)
        {
            node* temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL)
        {
            node* temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else
        {
            node* temp = findMin((*root)->right);
            (*root)->data = temp->data;
            (*root)->right = delete(&(*root)->right, temp->data);
        }
    }
    return *root;
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
    delete(&root, 5);
    printf("\n");
    preorder(root);

    printf("\n");

    return 0;
}