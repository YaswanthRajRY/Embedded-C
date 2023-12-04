// Finding Height of the binary search tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node* left;
    struct node* right;
} binaryTree;

binaryTree* createNode(char data)
{
    binaryTree* temp = (binaryTree*)malloc(sizeof(binaryTree));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

int printBinarytree(binaryTree* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int L = printBinarytree(root->left);
        int R = printBinarytree(root->right);

        if (L > R)
        {
            return L+1;
        }
        else
        {
            return R+1;
        }
    }
}

int main()
{
    binaryTree* root = createNode('e');
    root->left = createNode('b');
    root->right = createNode('f');
    root->left->left = createNode('a');
    root->left->right = createNode('d');
    root->right->right = createNode('h');
    root->left->right->left = createNode('c');

    printf("%d",printBinarytree(root));

    return 0;
}