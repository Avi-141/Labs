#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swim_down(int[],int,int);
void heapify(int[],int);
void solve(int[],int);

void heapify(int arr[],int array_size){
	int crawl = 1;
	printf("\nHeapifying now...\n");
	for(int i=1;i<=array_size;i++){
		printf("%d ",*(arr+i));
	}
	printf("\n");
   while(crawl<=array_size){
   	    printf("Calling top-down...\n");
		swim_down(arr,1,crawl);
		crawl+=1;
	}

    printf("Loading new array....\n");
	printf("\nNew contents after heapifying...\n");
	for(int i=1;i<crawl;i++)
		printf("%d ",*(arr+i));
	//printf("\n===....Next iteration....===\n");
}
void swim_down(int arr[],int rbegin,int crawl)
{
	int curr = crawl;
	while(curr>rbegin)
	{
		int t = curr/2;
		if(arr[t]<arr[curr])
		{
			printf("Swapping  (%d) and %d",arr[t],arr[curr]);
			printf("\n");
			int temp=arr[t];
			arr[t]=arr[curr];
			arr[curr]=temp;
			//swap((arr+t),(arr+curr));
			curr = t;
		}
		else return;
	}
}
void solve(int arr[],int n){
	for(int i=1;i<=n;i++){
		scanf("%d",(arr+i));
		if(i==1){
			printf("\nAdded first element \t%d\t  to the heap\n",*(arr+i));
		}
		else if(i>1){
			printf("Now call heapify function\n");
			heapify(arr,i);
		}
	}
}
int main(){
	int n;
	printf("Enter heap size");
	scanf("%d",&n);

	int *arr = (int*)calloc(n+1,sizeof(int));
	printf("\nEnter elements:\n");
	solve(arr,n);
	printf("\nThe heapified elements are: \n");
	for(int i=1;i<=n;i++)
		printf("%d\t",*(arr+i));


	printf("\n");

	return 0;
}