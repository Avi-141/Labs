#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define cout(x) printf("x");
#define systemprint(x) printf("%d\t",x);
void heapify(int arr[],int n,int i){
    //printf("Heapify\n");
	int large=i;
	int left=2*i+1;
	int right=2*i+2;

	if(left<n && arr[left]>arr[large]) 
	{
	   large=left;
	   printf("at %d ,left=curr_largest\n",2*i+1);
	}
	if(right<n& arr[right]>arr[large]){
	    large=right;
         printf("at %d,right=curr_largest\n",2*i+2);
	}

	if(large!=i){
		 printf("Largest not root\t...\t\n");
		 printf("Swapping root and largest\n");
	     int temp=arr[i];
	     arr[i]=arr[large];
	     arr[large]=temp;
	     printf("New root is \t%d \t\n",arr[i]);
          //printf("%d",arr[i]);
         
	     //printf("Heapifying again..\t..\t");
	     heapify(arr,n,large);
	}
}
void sorted(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i)
        systemprint(arr[i]); 
     //cout("\n"); 
} 
void heapsort(int arr[],int n){
	for (int i = n / 2 - 1; i >= 0; i--) 
	{
		printf("\nChecking curr node %d\t\n",arr[n/2 -1]);
		heapify(arr, n, i); 
	}
	for (int i=n-1; i>=0; i--) 
	{ 
		printf("Move root : %d to the end\n",arr[0]);
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		//swap(arr[0], arr[i]); 
		//printf("Heapify again..\t");
		heapify(arr, i, 0); 
	} 
}

int main(){
	int arr[]={6, 5, 3, 1, 8, 7, 2, 4};
	heapify(arr,8,0);
	heapsort(arr,8);
	sorted(arr,8);

	//for(int i=0;i<8;i++)
	//	printf("%d",arr[i]);
}