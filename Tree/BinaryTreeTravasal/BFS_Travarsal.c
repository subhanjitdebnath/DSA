#include <stdio.h>
#include <stdlib.h>

//bool
typedef enum 
{
    true,
    false,
}bool;
//Structure for BST
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}BST_Node;

/***************************QUEUE***************************/
//Structure for queue
typedef struct Node__
{
    BST_Node val;
    struct Node__* next;
}queue;

queue* __push(queue* front,BST_Node node)
{
    if(front == NULL)
    {
        front = (queue*)malloc(sizeof(queue));
        front->val = node;
        front->next = NULL;
        
    }
    else 
    {
       front->next = __push(front->next, node);
    }
    return front;
}
BST_Node __getnode(queue* front)
{
    return front->val;
}

queue* __pop(queue* front)
{
    BST_Node node;
    if(front!=NULL)
    {
        node = front->val;
        front = front->next;
        return front;
    }
    else {
    return NULL;
    }
}

bool __isqueueempty(queue* front)
{
    return front == NULL? true:false;
}
/***************************QUEUE***************************/

BST_Node* CreateNode(int val)
{
    BST_Node* new = (BST_Node*)malloc(sizeof(BST_Node));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

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
    else {
        root->right = InseartNode(root->right, val);
    }
    return root;
}

void Traversed_Inorder(BST_Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else {
        
        Traversed_Inorder(root->left);
        printf("%d ",root->val);
        Traversed_Inorder(root->right);
    }
}

void BFS_traverse(BST_Node* root)
{
    queue *front = NULL;
    BST_Node node;

    if(root != NULL)
    {
        front = __push(front, *root);
        while(__isqueueempty(front) == false)
        {
            node = __getnode(front);
            printf("%d ",node.val);
            if(node.left !=NULL)
            {
               front = __push(front, *node.left);
            }
            if(node.right !=NULL)
            {
                front =__push(front, *node.right);
            }
            front = __pop(front);
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
    printf("root.value =  %d ",root->val);
    printf("\nInorder Traverse\n");
    Traversed_Inorder(root);
    printf("\nroot.value =  %d ",root->val);
    printf("\nBFS Traverse\n");
    BFS_traverse(root);
    return 0;
}