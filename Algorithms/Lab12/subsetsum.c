#include <stdio.h>
#include <stdlib.h>
void printarr(int arr[],int ss[],int n){
	for (int i = 0; i < n; ++i){
		if(ss[i] == 1){
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}
void subsetsum(int arr[],int ss[],int i,int n,int sum,int d){
	if(sum > d){
		printf("Deadend: ");
		printarr(arr,ss,n);
		return;
	}
	if(sum == d){
		printarr(arr,ss,n);
	}
	else{
		if(i<n){
			subsetsum(arr,ss,i+1,n,sum,d);
			ss[i] = 1;
			subsetsum(arr,ss,i+1,n,sum+arr[i],d);
			ss[i] = 0;
		}
	}
}
int main(int argc, char const *argv[])
{
	int arr[] = {4,9,11,16,27};
	int n = sizeof(arr)/sizeof(int);
	int ss[n];
	int sum = 20;
	subsetsum(arr,ss,0,n,0,sum);
	return 0;
}