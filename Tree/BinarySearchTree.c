#include <stdio.h>
#include <stdlib.h>

//Structure for the BST
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}BST_Node;

//Creating a Node
BST_Node* CreateNode(int val)
{
    BST_Node *newnode = (BST_Node*)malloc(sizeof(struct Node));
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
    else if (val<=root->val) 
    {
        root->left = InseartNode(root->left, val);
    }
    else 
    {
        root->right = InseartNode(root->right, val);
    }
    return root;
}
//Search Node
int SearchNode(BST_Node *root,int val)
{
    if(root == NULL)
    {
        return 0;
    }
    else if (root->val == val) 
    {
        return 1;
    }
    else if (root->val > val) 
    {
        return SearchNode(root->left, val);
    }
    else 
    {
        return SearchNode(root->right, val);
    }
}

int main()
{
    int a[]={15,56,20,1,13,2,4,8,9,5,6,41},len,val;
    len = sizeof(a)/sizeof(int);

    BST_Node* root = NULL;
    for(int i=0;i<len;i++)
    {
        root = InseartNode(root, a[i]);
    }

    printf("Enter the value to search = ");
    scanf_s("%d",&val);
    if(SearchNode(root,  val) == 1)
    {
        printf("Value Found");
    }
    else 
    {
        printf("Value not Found");
    }

}