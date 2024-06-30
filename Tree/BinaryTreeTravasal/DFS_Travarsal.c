#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    PreOrder,
    Inorder,
    Postorder
}DFS_Type;

//Struct for the BST
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
} BST_Node;

//Create Node
BST_Node* CreateNode(int val)
{
    BST_Node* new = (BST_Node*)malloc(sizeof(BST_Node));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

//Inseart Node
BST_Node* InseartNode(BST_Node* root, int val)
{
    if(root == NULL)
    {
        root = CreateNode(val);
    }
    else if (val <= root->val) 
    {
        root->left = InseartNode(root->left,val);
    }
    else 
    {
        root->right = InseartNode(root->right,val);
    }
    return root;
}

//Search
int SearchNode(BST_Node* root,int val)
{
    if(root == NULL)
    {
        return -1;
    }
    else if(root->val == val)
    {
        return 1;
    }
    else 
    {
        if(val<root->val)
        {
            return SearchNode(root->left, val);
        }
        else {
            return SearchNode(root->right, val);
        }
    }
}

//Traversal
void Traversal(BST_Node* root,DFS_Type type)
{
    if(root == NULL)
    {
        return;
    }
    else 
    {
        switch(type)
        {
            case PreOrder:
                printf(" %d",root->val);
                Traversal(root->left,type);
                Traversal(root->right,type);
                break;

            case Inorder:
                Traversal(root->left,type);
                printf(" %d",root->val);
                Traversal(root->right,type);
                break;

            case Postorder:
                Traversal(root->left,type);
                Traversal(root->right,type);
                printf(" %d",root->val);
                break;

            default:
                break;
        }
    }
}

int main()
{
    int a[]={9,1,5,7,3,4,2,10,15,36,11},len;
    len = sizeof(a)/sizeof(int);
    BST_Node *root = NULL;
    for(int i=0;i<len;i++)
    {
        root = InseartNode(root, a[i]);
    }
    printf("Pre-Order Traversal\n");
    Traversal(root,PreOrder);
    printf("\nIn-Order Traversal\n");
    Traversal(root,Inorder);
    printf("\nPost-Order Traversal\n");
    Traversal(root,Postorder);

    return 0;
}