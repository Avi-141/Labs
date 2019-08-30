#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
typedef enum { NO, YES } BOOL;

static int op=0;
//opcount 
//where do i increment it and return ?

int max(int a,int b)
{
	int ans=a>b?a:b;
	return ans;
}

BOOL checksubsum (int arr[], int n, int sum) 
{ 
  op+=1;
if (sum == 0) 
	return YES; 
if (n == 0 && sum != 0) 
	return NO; 

int last=arr[n-1];
//without last
if (last > sum) 
	return checksubsum (arr, n-1, sum); 

//with last or without last
return checksubsum (arr, n-1, sum) || 
		checksubsum (arr, n-1, sum-last); 
} 


BOOL findPartiion (int arr[], int n) 
{ 
	
	int sum = 0; 
	for (int i = 0; i < n; i++) 
	sum += arr[i]; 

    //printf("%d\n",sum/2);

	
	if (sum%2 != 0) 
	return NO; 

	
	return checksubsum (arr, n, sum/2); 
} 

int main() 
{ 

	int n;
	printf("Enter the set length\n" );
	scanf("%d",&n);

	int set[n];
	for(int i=0;i<n;i++)
		scanf("%d",&set[i]);
   int sum;
   //printf("Check for sum?\n");
   //scanf("%d",&sum);
   BOOL part=findPartiion(set,n);
   if(part==1)
   {
   	printf("Can be partitioned\n");
   	printf("Opcount is %d\n",op);
   }
   else printf("Bhak\n");
  
 }  