#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode treeNode;
struct treeNode
{
    char* key;
    float value;
    struct treeNode* left, *right;
};

treeNode* constructTreesNode(char* str)
{
    treeNode* node = malloc(sizeof(treeNode));
    node->key = (char *)malloc(strlen(str)+1);
    strcpy(node->key, str);
    node->left = node->right = NULL;
    return node;
}

void setValue(treeNode* node, float value)
{
    node->value = value;
}

void freeNode(treeNode* node)
{
    free(node->key);
    free(node);
}

treeNode* insert(treeNode* node, char *key)
{
    if (node == NULL)
        return(constructTreesNode(key));
    if (strcasecmp(key, node->key)<0)
        node->left  = insert(node->left, key);
    else if (strcasecmp(key, node->key)>0)
        node->right = insert(node->right, key);
    return node;
}

void inorder(treeNode* node)
{
    if (node)
    {
        inorder(node->left);
        printf("%s\n", node->key);
        inorder(node->right);
    }
}
