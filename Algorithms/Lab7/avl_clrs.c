#ifndef _avl_h

#define _avl_h

typedef struct Node {
  struct Node *parent, *left, *right;
  int data, height;
} Node;

typedef struct AVLTree {
  Node *root;
} AVLTree;

Node *mknode(int data);
AVLTree *mktree(void);

void traverse(Node *root);
Node *find(Node *root, int key);

Node *insert(AVLTree *t, Node *z);

void free_tree(AVLTree *t);
void delete_node(AVLTree *t, Node *z);

void verify_avl_property(Node *root);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int max(int a,int b){
    return a>b?a:b;
}

void printnode(Node *root) {
  printf("(%d H:%d L:%d R:%d P:%d) ", root->data, root->height,
         (root->left != NULL) ? root->left->data : -1,
         (root->right != NULL) ? root->right->data : -1,
         (root->parent != NULL) ? root->parent->data : -1);
}

int height(Node *x) {
  if (x == NULL)
    return -1;
  else
    return x->height;
}

void update_height(Node *x) {
  x->height = max(height(x->left), height(x->right)) + 1;
}

void left_rotate(AVLTree *t, Node *x);
void right_rotate(AVLTree *t, Node *x);

void rebalance(AVLTree *t, Node *x) {
  while (x != NULL) {
    update_height(x);
    if (height(x->left) >= 2 + height(x->right)) {
      if (height(x->left->left) >= height(x->left->right))
        right_rotate(t, x);
      else {
        left_rotate(t, x->left);
        right_rotate(t, x);
      }
    } else if (height(x->right) >= 2 + height(x->left)) {
      if (height(x->right->right) >= height(x->right->left))
        left_rotate(t, x);
      else {
        right_rotate(t, x->right);
        left_rotate(t, x);
      }
    }
    x = x->parent;
  }
}

void left_rotate(AVLTree *t, Node *x) {
  Node *y = x->right;
  assert(y != NULL);

  x->right = y->left;
  if (y->left != NULL)
    y->left->parent = x;

  y->parent = x->parent;

  if (x->parent == NULL)
    t->root = y;
  else if (x == y->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;

  y->left = x;
  x->parent = y;

  update_height(x);
  update_height(y);
}

/* y->left should not be NULL */
void right_rotate(AVLTree *t, Node *y) {
  Node *x = y->left;
  assert(x != NULL);

  y->left = x->right;
  if (x->right != NULL)
    x->right->parent = y;

  x->parent = y->parent;

  if (y->parent == NULL)
    t->root = x;
  else if (y == y->parent->left)
    y->parent->left = x;
  else
    y->parent->right = x;

  x->right = y;
  y->parent = x;

  update_height(y);
  update_height(x);
}

void verify_avl_property(Node *root) {
  if (root == NULL)
    return;
  int s1 = height(root->left);
  int s2 = height(root->right);
  if (abs(s1 - s2) >= 2) {
    printf("verifying avl property failed at node: %d\n", root->data);
    exit(1);
  }
  verify_avl_property(root->left);
  verify_avl_property(root->right);
}


Node *mknode(int data) {
  Node *n = malloc(sizeof(Node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  n->parent = NULL;
  n->height = 0;
  return n;
}

AVLTree *mktree(void) {
  AVLTree *t = malloc(sizeof(AVLTree));
  t->root = NULL;
  return t;
}

void traverse(Node *root) {
  if (root != NULL) {
    traverse(root->left);
    printnode(root);
    traverse(root->right);
  }

}

Node *find(Node *root, int key) {
  Node *cur = root;
  while (cur != NULL) {
    if (cur->data == key)
      break;
    else if (key < cur->data)
      cur = cur->left;
    else
      cur = cur->right;
  }
  return cur;
}

Node *insert(AVLTree *t, Node *z) {
  Node *y = NULL;
  Node *x = t->root;
  while (x != NULL) {
    y = x;
    if (z->data < x->data)
      x = x->left;
    else
      x = x->right;
  }
  z->parent = y;
  if (y == NULL)
    t->root = z;
  else if (z->data < y->data)
    y->left = z;
  else
    y->right = z;
  rebalance(t, z);
  return z;
}



int main(){
    AVLTree* t = mktree();
    int arr[] = {5,2,6,11,7,8,13};

    for(int i=0;i<7;i++){
        insert(t,mknode(arr[i]));
    }

    traverse(t->root);
    verify_avl_property(t->root);   

}
