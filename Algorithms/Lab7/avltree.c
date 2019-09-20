#include<stdio.h> 
#include<stdlib.h> 
#define maxxx(a, b) ((a > b) ? a : b)
#define noleaf NULL
struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 
int max(int a, int b){ 
	if(a>b)
		return a; return b;} 

int height(struct Node *root) { 
	if (root == noleaf) 
		return 0; 
	return root->height; 
}

int bfactor(struct Node *root) { 
	if (root == noleaf) 
		return 0; 
	return height(root->left) - height(root->right); 
} 

struct Node* newNode(int key) { 
	struct Node* node=(struct Node*)malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = noleaf; 
	node->right = noleaf; 
	node->height = 1;
	return(node); 
} 
void pre(struct Node *root) 
{ 
	if(root != noleaf) 
	{ 
		printf("%d ", root->key); 
		pre(root->left); 
		pre(root->right); 
	} 
} 
void post(struct Node *root) 
{ 
	if(root != noleaf) 
	{ 	
		post(root->left); 
		post(root->right);
		printf("%d ", root->key); 
 
	} 
} 
struct Node *rightrot(struct Node *root){ 
	struct Node *lchild = root->left; 
	struct Node *Rnext= lchild->right; 
    lchild->right = root; 
	root->left = Rnext; 
    root->height = max(height(root->left), height(root->right))+1; 
	lchild->height = max(height(lchild->left), height(lchild->right))+1; 
   
   return lchild; 
} 

struct Node *leftrot(struct Node *root) 
{ 
	struct Node *rchild= root->right; 
	struct Node *Lnext = rchild->left; 
    rchild->left = root; 
	root->right = Lnext; 
    root->height = max(height(root->left), height(root->right))+1; 
	rchild->height = max(height(rchild->left), height(rchild->right))+1; 

return rchild; 
} 
struct Node* avl_insert(struct Node* node, int key) 
{ 

	if (node == noleaf) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = avl_insert(node->left, key); 
	else if (key > node->key) 
		node->right = avl_insert(node->right, key); 
	else 
		return node; 

    int factor;
	node->height = 1 + max(height(node->left), height(node->right)); 
	factor = bfactor(node);
	if (factor > 1 && key < node->left->key) 
		return rightrot(node); 
	if (factor < -1 && key > node->right->key) 
		return leftrot(node); 
	if (factor > 1 && key > node->left->key) 
	{ 
		node->left = leftrot(node->left); 
		return rightrot(node); 
	}
	if (factor < -1 && key < node->right->key) 
	{ 
		node->right = rightrot(node->right); 
		return leftrot(node); 
	} 
return node;  
} 
int main() { 
struct Node *root = noleaf; 
root=avl_insert(root,10);
root=avl_insert(root,9);
root=avl_insert(root,23);
root=avl_insert(root,22);
root=avl_insert(root,11);
root=avl_insert(root,0);
root=avl_insert(root,8);
root=avl_insert(root,5);
root=avl_insert(root,78);root=avl_insert(root,234);
root=avl_insert(root,7);

printf("AVL tree pre-traversal\n"); 
pre(root); 
printf("\n");
printf("AVL tree post-traversal\n");
post(root); 


return 0; 
} 
