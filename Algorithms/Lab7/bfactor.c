#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define noleaf NULL

struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; };

struct Node* build(int key){ 
    struct Node* node =(struct Node*)malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = noleaf; 
    node->right  = noleaf; 
    node->height = 1; 
    return(node); 
} 
int max(int a, int b){ 
  if(a>b)
    return a; 
  return b;
}

int height(struct Node *root){ 
    if (root == noleaf) 
        return 0; 
    return root->height; 
} 

int bfactor(struct Node *root) 
{ 
    if (root == noleaf) 
        return 0; 
    return height(root->left) - height(root->right); 
} 

struct Node* insert(struct Node* node, int key) 
{ 
    if (node == noleaf) 
        return(build(key)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 

    node->height = 1 + max(height(node->left),height(node->right)); 

    return node;
}

void pre(struct Node *root) { 
    if(root != noleaf) 
    { 
        printf("Current Node : %d ", root->key); 
        printf("Cannot be |-1<= Bfactor <=1| since this is NOT AVL: %d \n", bfactor(root));
        pre(root->left); 
        pre(root->right); 
    } 
}

int main() 
{ 
    
  struct Node *root = noleaf; 

  int k=1; int n;
  printf("BST balance factor\n");
  printf("Enter 0 to quit\n");

  do{
   scanf("%d",&n);
    if(n==0)
        k=0;
    else
    root = insert(root,n);

  } while(k!=0);

  printf("Balance factors as per pre: \n"); 
  pre(root); 
}