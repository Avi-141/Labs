#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define string char*
#define intptr int *

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

void swap(intptr x,intptr y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   int opcount=0;
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  
       {
       	    opcount+=1;
           if (arr[j] > arr[j+1]) 
           {
           	  
              swap(&arr[j], &arr[j+1]); 
           }
       }
     printf("The opcount is\t %d",opcount);
}


int main()
{
	
	int n;
	printf("Enter the list len\n" );
	scanf("%d",&n);
	printf("Enter the list\n");

	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	bubbleSort(a,n);

	clock_t start_time, end_time;
	double total_time;
	
	return 0;
} 
