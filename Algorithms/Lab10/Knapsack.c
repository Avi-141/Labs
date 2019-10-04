#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

int max(int a, int b){ 
  if(a>b)return a;
  return b; 
  } 

int kp(int WT, int wt[], int val[], int n) { 
int i, w; 

int knap[n+1][WT+1];

memset(knap,-1,(WT*n)*sizeof(int)); 

for (i = 0; i <= n; i++) 
{ 
	for (w = 0; w <= WT; w++) 
	{ 
		if (i==0 || w==0) 
			knap[i][w] = 0; 
		else if (wt[i-1] <= w) 
				knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]); 
		else
				knap[i][w] = knap[i-1][w]; 
	} 
} 
for(int i=0;i<n;i++){
	for(int j=0;j<WT;j++)
		printf("%4d",knap[i][j]);
 printf("\n");
}

return knap[n][WT]; 
} 

int main() 
{ 
	printf("Enter #val,val arr,wt arr,max wt\n");
	int n;
	scanf("%d",&n);
	int val[n];
    int wt[n];
	for(int i=0;i<n;i++)
		scanf("%d",&val[i]);
    for(int i=0;i<n;i++)
		scanf("%d",&wt[i]);	

	int WT;
	scanf("%d",&WT);
	printf("Optimal ans=%2d", kp(WT, wt, val, n)); 
	return 0; 
} 
