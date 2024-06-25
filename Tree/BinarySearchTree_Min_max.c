#include <stdio.h>
#include <stdlib.h>

//Structure that will used for BST
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}BST_Node;

//Creating a new node
BST_Node* CreateNode(int val)
{
    BST_Node *newnode = (BST_Node*)malloc(sizeof(BST_Node));
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

//Insearting a node
BST_Node* InseartNode(BST_Node* root,int val)
{
    if(root == NULL)
    {
        root = CreateNode(val);
    }
    else if(val<=root->val)
    {
        root->left = InseartNode(root->left, val);
    }
    else 
    {
        root->right = InseartNode(root->right, val);
    }

    return root;
}

//Search node
int SearchNode(BST_Node *root,int val)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->val == val)
    {
        return 1;
    }
    else if(val <= root->val)
    {
        return SearchNode(root->left, val);
    }
    else {
        return SearchNode(root->right, val);
    }
}

//Find Max Value
int MaxVale(BST_Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->right == NULL)
    {
        return root->val;
    }
    else
    {
        return MaxVale(root->right);
    }
}
//Find Max Value
int MinVale(BST_Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL)
    {
        return root->val;
    }
    else
    {
        return MaxVale(root->left);
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

    printf("Enter the Number to Search = ");
    scanf("%d",&val);

    if(SearchNode(root, val) == 1)
    {
        printf("\nFound" );
    }
    else {
    printf("\nNot Found" );
    }

    printf("\n The max number = %d",MaxVale(root) );
    printf("\n The min number = %d",MinVale(root) );
    return 0;
}