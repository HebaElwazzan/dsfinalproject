#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct  Node* left;
    struct Node*right;
} Node;
Node* newNode(int v)
{
    Node* n=malloc(sizeof(Node));
    n->data=v;
    n->left=NULL;
    n->right=NULL;
    return n;
}
Node*insert(Node* root,int value)
{
    if(root==NULL)
        return newNode(value);
    else if(value<root->data)
        root->left= insert(root->left,value);
    else
        root->right=insert(root->right,value);
    return root;
}
Node* searhRec(Node* root,int x)
{
    if(root==NULL)
        return NULL;
    else if (root->data==x)
        return root;
    else if (x<root->data)
        return searhRec(root->left,x);
    else
        return searhRec(root->right,x);
}

Node* search(Node* root,int x)
{

    while(root)
    {
        if(root->data==x)
            return root;
        else if (x<root->data)
            root=root->left;
        else
            root=root->right;
    }
    return NULL;
}
void PreOrder(Node* root)
{
    if(root)
    {
        printf("%d",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }

}
void inOrder(Node* root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d",root->data);
        inOrder(root->right);
    }

}
int max(int x ,int y )
{
    return x>y?x:y;
}
int height(Node* root)
{
    if(root==NULL)
        return -1;
    else
        return 1+max(height(root->left),height(root->right));

}
int count(Node* root)
{
    if(root==NULL)
        return 0;
    else
        return 1+count(root->left)+count(root->right);

}
int main()
{

    return 0;
}
