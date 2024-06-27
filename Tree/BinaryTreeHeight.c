#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
//Structure for the BST
typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
}BST_Node;

//Create Node
BST_Node* Craetenode(int val)
{
    BST_Node* newnode = (BST_Node*)malloc(sizeof(BST_Node));
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

//Inseart Node
BST_Node* InseartNode(BST_Node* root,int val)
{
    if(root == NULL)
    {
        root = Craetenode(val);
    }
    else if(val <= root->val)
    {
        root->left = InseartNode(root->left, val);
    }
    else 
    {
        root->right = InseartNode(root->right, val);
    }
    return root;
}

//Search Val
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
    else if(root->val < val)
    {
        return Search(root->right, val);
    }
    else {
    return Search(root->left, val);
    }
}

//Height of BST

int FindHeight(BST_Node *root)
{
    if(root == NULL)
    {
        return -1;
    }
    return (max(FindHeight(root->left), FindHeight(root->right))+1);
}

int main()
{
    int a[] = {6,5,8,4,2,1,25,21,29,10,12},len,val;
    len = sizeof(a)/sizeof(int);
    BST_Node *root =NULL;
    for(int i=0;i<len;i++)
    {
        root = InseartNode(root, a[i]);
    }
    printf("Enter the Value to Search = ");
    scanf(" %d",&val);
    if(Search(root, val) == 1)
    {
        printf("\nFound");
    }
    else 
    {
        printf("\nNot Found");
    }
    printf("\n Height of Tree is = %d",FindHeight(root));

}