#include <stdio.h>
#include <stdlib.h>

//Structure for the BST
typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
}BST_Node;

//Function to create a node
BST_Node* Createnode(int val)
{
    BST_Node *newnode = (BST_Node*)malloc(sizeof(BST_Node));
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
//Function to inseart a node
BST_Node* InseartNode(BST_Node *root,int val)
{
    if(root == NULL)
    {
        root = Createnode(val);
    }
    else if (val <= root->val) 
    {
        root->left = InseartNode(root->left, val);
    }
    else
    {
        root->right = InseartNode(root->right, val);
    }
    return root;
}
//Search the value in BST

int Search(BST_Node *root,int val)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->val == val)
    {
        return 1;
    }
    else if (root->val >= val)
    {
        return Search(root->left,val);
    }
    else 
    {
        return Search(root->right,val);
    }
}

int main()
{
    int a[]={8,7,9,5,4,6,2,5,8,9,3,1,15},len,val;
    len = sizeof(a)/sizeof(int);
    BST_Node *root = NULL;
    for(int i=0;i<len;i++)
    {
        root = InseartNode(root, a[i]);
    }
    printf("Enter the Number to search = ");
    scanf("%d",&val);

    if(Search(root, val) == 1)
    {
        printf("Found");
    }
    else 
    {
        printf("Not Found");
    }
}