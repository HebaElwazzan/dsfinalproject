#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
   char *key;
   struct Node* left,*right;
};

Node * constructNode(char * str){
  Node * p=malloc(sizeof( Node));
  p->key=(char *)malloc(strlen(str)+1);
  strcpy(p->key,str);
  p->left=p->right=NULL;
  return p;
}
char * getVal(Node *node) {
  return node->key;
}
void freeNode(Node *node){
  free(node->key);
  free(node);
}

int count(Node *node){
    if (node) return 1+count(node->left)+count(node->right);
    return 0;
}


Node* insert(Node* node, char *key)
{
    /* 1.  Perform the normal BST insertion */
    //printf("{{{inserting %d}}}\n",key);
    if (node == NULL)
        return(constructNode(key));

    if (strcmpi(key ,node->key)<0)
        node->left  = insert(node->left, key);
    else if (strcmpi(key ,node->key)>0)
        node->right = insert(node->right, key);
    // Equal keys are not allowed in BST
    return node;
}

void printPreorder(Node *root,int level,char leftORright){
    if (root) {
        int i; for (i=0;i<level;i++) printf("\t");
        printf("%c :%s\n",leftORright,root->key);
        printPreorder(root->left,level+1,'L');
        printPreorder(root->right,level+1,'R');
    }
}

void preOrder(Node *root){
   printPreorder(root,0,'*');
}
Node * minValueNode(Node* node)
{
    Node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    return current;
}
Node * maxValueNode(Node* node)
{
    if (!node) return NULL;
    if (node->right) return maxValueNode(node->right);
    return node;
}

Node* deleteNode(Node* root, char * key)
{
    // base case
    if (root == NULL) return root;
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (strcmpi(key ,root->key)<0)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (strcmpi(key ,root->key)>0)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            freeNode(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            freeNode(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        free(root->key);root->key=malloc(strlen(temp->key)+1);
        strcpy(root->key,temp->key);
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
        //printf("(%s)",root->right->key);
    }
    return root;
}

void mirror(Node *node){
  if (node){
      Node *temp=node->left;
      node->left=node->right;
      node->right=temp;
      mirror(node->left);
      mirror(node->right);
  }
}


Node *search(Node *root,char * key){
    if(!root) return root;
    if(!key){printf("Invalid search key!\n");return NULL;}
    if(strcmp(key,root->key)<0) return search(root->left,key);
    else if(strcmp(key,root->key)>0) return search(root->right,key);
    else return root;
}

void fillTest(Node** root){
    printf( "Constructing tree\n\n" );
    char key[5] ="";
    for(int j=1 ;j<4;j++ ){
        memset(&key,0,5);
        for(int i=0; i<26; i++){
            for(int k = 0;k<j;k++) key[k]= i+'a';
            *root= insert(*root,key);
        }
    }
    printf( "\n\nTree constructed\n\n" );
}

void searchTest(Node* root){
    char key[5] ="";
    int failed =0;
    for(int j=1 ;j<4;j++ ){
        memset(&key,0,5);
        for(int i=0; i<26; i++){
            for(int k = 0;k<j;k++) key[k]= i+'a';
            Node * foundNode = search(root,key);
            if(foundNode)printf("Found Node: [target key: %s, found Key %s]\n",key,foundNode->key);
            else {printf("failed at finding Node\n");failed++;}
        }
    }
    printf( "\nsearch completed, failed %d\n",failed);
}


int main(void){
    Node *root =NULL;
    fillTest(&root);
    searchTest(root);
}