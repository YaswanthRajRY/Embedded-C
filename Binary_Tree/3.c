#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}node;

node* createNode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node* addNodeToTree(node* tree, int data)
{
    if (tree == NULL)
    {
        return createNode(data);
    }

    if(tree->data >= data)
    {
        tree->left = addNodeToTree(tree->left, data);
    }
    else
    {
        if (tree->data < data)
        {
            tree->right = addNodeToTree(tree->right, data);
        }
    }
    return tree;
}

void binaryTree(node** root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else
    {
        node* temp = *root;
        *root = addNodeToTree(temp, data);
    }
}

void postOrder(node* head)
{
    if (head == NULL)
    {
        return;
    }
    
    postOrder(head->left);
    postOrder(head->right);
    printf("%d ",head->data);    
}


void preOrder(node* head)
{
    if (head == NULL)
    {
        return;
    }
    
    printf("%d ",head->data);    
    preOrder(head->left);
    preOrder(head->right);
}


void inOrder(node* head)
{
    if (head == NULL)
    {
        return;
    }
    
    inOrder(head->left);
    printf("%d ",head->data);    
    inOrder(head->right);
}

int main()
{
    node* root = NULL;

    binaryTree(&root, 5);
    binaryTree(&root, 6);
    binaryTree(&root, 2);
    binaryTree(&root, 1);
    binaryTree(&root, 3);

    printf("Root-> %d\n", root->data);

    printf("Pre Order: ");
    postOrder(root);
    printf("\n");
    printf("In Order: ");
    inOrder(root);
    printf("\n");
    printf("Post Order: ");
    preOrder(root);

    return 0;
}
