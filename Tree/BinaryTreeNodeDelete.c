#include <stdio.h>
#include <stdlib.h>

//Structure for BST
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}BST_Node;

//Create a node
BST_Node* CreateNode(int val)
{
    BST_Node* new = (BST_Node*)malloc(sizeof(BST_Node));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

//Inseart New node
BST_Node* InseartNode(BST_Node* root,int val)
{
    if(root == NULL)
    {
        root = CreateNode(val);
    }
    else if(val<=root->val)
    {
        root->left = InseartNode(root->left,  val);
    }
    else 
    {
        root->right = InseartNode(root->right,  val);
    }
    return root;
}

//BST Traversal 
void Traversal(BST_Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        Traversal(root->left);
        printf("%d ",root->val);
        Traversal(root->right);
    }
}
//Find Min node
BST_Node* FindMin(BST_Node *root)
{
    if(root == NULL)
    {
        return root;
    }
    else 
    {
        if(root->left == NULL)
        {
            return root;
        }
        else 
        {
            return root->left;
        }
    }
}
//Delete Node
BST_Node* DeleNode(BST_Node *root,int val)
{
    if(root == NULL)
    {
        return root;
    }
    else 
    {
        if(val<root->val)
        {
            root->left = DeleNode(root->left, val);
        }
        else if (val>root->val) 
        {
            root->right = DeleNode(root->right, val);
        }
        else 
        {
            if(root->left == NULL && root->right == NULL)
            {
                free(root);
                root = NULL;
            }
            else if(root->left == NULL)
            {
                BST_Node *temp = root;
                root = root->right;
                free(temp);
            }
            else if(root->right == NULL)
            {
                BST_Node *temp = root;
                root = root->left;
                free(temp);
            }
            else 
            {
                //Find the minimum in the subtree
                BST_Node *temp = FindMin(root->right);
                root->val = temp->val;
                root->right = DeleNode(root->right, temp->val);
            }
        
        }
    
    }
    return root;
}

int main()
{
    int a[]={9,1,5,7,3,4,2,10,15,36,11},len;
    len = sizeof(a)/sizeof(int);
    BST_Node *root = NULL;
    for(int i=0;i<len;i++)
    {
        root = InseartNode(root,a[i]);
    }
    Traversal(root);
    printf("\nAfter Delete\n");
    DeleNode(root, 10);
    Traversal(root);


}