#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}Nodes; 

int count=0;
int countall(struct Node*root)
{
	if(root==NULL)
		return 0;
	if(root!=NULL)
	{
      countall(root->left);
       count++;
      countall(root->right);
	}
return count;
}
/*int cnt(struct Node* root) 
{ 
	if (root == NULL) 
	return 0; 
    int ans=0;
	if (root->left && root->right) 
	ans+=1; 

	ans += (cnt(root->left) + cnt(root->right)); 
	return ans; 
} */

struct Node* newnode(int data) 
{ 
	struct Node* node =(struct Node*)malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

int main(void) 
{ 
	struct Node *root = newnode(2); 
	root->left = newnode(7); 
	root->right = newnode(5); 
	root->left->right = newnode(6); 
	root->left->right->left = newnode(1); 
	root->left->right->right = newnode(11); 
	root->right->right = newnode(9); 
	root->right->right->left = newnode(4); 

    printf("Total nodes %d",countall(root)); 

	return 0; 
} 
