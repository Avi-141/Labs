#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}nn;
struct Node* newnode(int data) 
{ 
	struct Node* node =(struct Node*)malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 


int height (struct Node*root) {
	if (root == NULL)
		return 0;
	int left = height(root->left);
	int right = height(root->right);
	if(left>right)
		return(left + 1);
	else return(right + 1);
}
int k=0;
int arr[100]; // made thid for path

int diameter (struct Node* root) {
	if (root == NULL)
		return 0;
	int leftd = diameter(root->left);
	int rightd = diameter(root->right);
	int dia;
	if(leftd>rightd)
      dia=leftd ;
	else 
		dia=rightd;
	int longest= 1 + height(root->left) + height(root->right);
	return (longest > dia) ? longest: dia;
}

int main()
{
   struct Node *root = newnode(2); 
	root->left = newnode(7); 
	root->right = newnode(5); 
	root->left->right = newnode(6); 
	root->left->right->left = newnode(1); 
	root->left->right->right = newnode(11); 
	root->right->right = newnode(9); 
	root->right->right->left = newnode(4); 
	root->right->left=newnode(21);
	root->right->right->left->right=newnode(98);
	printf("%d\n",diameter(root));
}
