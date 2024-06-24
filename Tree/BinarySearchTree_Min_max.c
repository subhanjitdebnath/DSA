#include <stdio.h>
#include <stdlib.h>

//Structure for the BST
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}BST_Node;

//Create a node
BST_Node* Createnode(int val)
{
    BST_Node* newnode = (BST_Node*)malloc(sizeof(BST_Node));
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

//Inseart a node
BST_Node* InseartNode(BST_Node* root,int val)
{
    if(root == NULL)
    {
        root = Createnode(val);
    }
    else if (val<=root->val) 
    {
        root->left = InseartNode(root->left,  val);
    }
    else 
    {
        root->right = InseartNode(root->right,  val);
    }
}

//Search a node
int Search(BST_Node* root,int val)
{
    if(root == NULL)
    {
        return 0;
    }
    else if (root->val == val) 
    {
        return 1;
    }
    else if (val<root->val) 
    {
        return Search(root->left, val);
    }
    else
    {
        return Search(root->right, val);
    }
}

//Max Element
int MaxElement(BST_Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if (root->right == NULL) 
    {
        return root->val;
    }
    else 
    {
        return MaxElement(root->right);
    }
}
//Min Element
int MinElement(BST_Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL) 
    {
        return root->val;
    }
    else 
    {
        return MinElement(root->left);
    }
}

int main()
{
    int a[]={15,56,20,1,13,2,4,8,9,5,6,41},len,val;
    len = sizeof(a)/sizeof(int);
    BST_Node *root = NULL;
    for(int i=0;i<len;i++)
    {
        root = InseartNode(root,a[i]);
    }
    
    printf("Enter the Number to Search = ");
    scanf_s("%d",&val);
    if(Search(root, val) == 1)
    {
        printf("Value Found\n");
    }
    else 
    {
        printf("Value Not Found\n");
    }

    printf("Max Value = %d\n",MaxElement(root));
    printf("Min Value = %d\n",MinElement(root));
}