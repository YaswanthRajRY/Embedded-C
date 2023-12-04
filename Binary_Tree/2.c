// create binary tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node* left;
    struct node* right;    
} binaryTree;

binaryTree* root = NULL;

binaryTree* createNode(int data)
{
    binaryTree* temp = (binaryTree*)malloc(sizeof(binaryTree));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

binaryTree* sortedBinarytree(binaryTree* node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }

    if (node->data >= data)
    {
        node->left = sortedBinarytree(node->left, data);
    }
    else
    {
        node->right = sortedBinarytree(node->right, data);
    }

    return node;
}
    
void display(binaryTree* node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d",node->data);
    display(node->left);
    display(node->right);
}

int main()
{
    root = sortedBinarytree(root, 10);
    root = sortedBinarytree(root, 8);
    root = sortedBinarytree(root, 9);
    root = sortedBinarytree(root, 6);
    root = sortedBinarytree(root, 11);

    display(root);
    
    return 0;
}