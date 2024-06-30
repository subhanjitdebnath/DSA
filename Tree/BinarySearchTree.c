
#include <stdio.h>
#include <stdlib.h>

//Structure to be used

typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}BST_Node;

//Cearting a node
BST_Node* Createnode(int val)
{
    BST_Node* new = (BST_Node*)malloc(sizeof(BST_Node));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

//Inseart a node

BST_Node* InseartNode(BST_Node* root, int val)
{
    if(root == NULL)
    {
        root = Createnode(val);
    }
    else if(val<=root->val)
    {
        root->left = InseartNode(root->left, val);
    }
    else {
        root->right = InseartNode(root->right, val);
    }
    return root;
}

//Search a Value

int SearchData(BST_Node* root,int val)
{
    if(root == NULL)
    {
        return -1;
    }
    else if(root->val == val)
    {
        return 1;
    }
    else {
        if(val < root->val)
        {
            return SearchData(root->left, val);
        }
        else {
            return SearchData(root->right, val);
        }
    }
}

int main()
{
    int a[]={15,22,4,5,8,7,32,88,94,75,1},len,val;
    len = sizeof(a)/sizeof(int);
    BST_Node *root = NULL;
    for(int i=0;i<len;i++)
    {
        root = InseartNode(root, a[i]);
    }
    printf("Enter the value to Search = ");
    scanf("%d",&val);
    if(SearchData(root, val) == 1)
    {
        printf("\n Found");
    }
    else {
        printf("\n Not Found");
    }
}