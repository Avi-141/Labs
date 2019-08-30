#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(int arr[],int lo,int mid,int hi)
{
	int first=mid-lo+1;
	int second=hi-mid;

	int left[first],right[second];

	for(int i=0;i<first;i++){
		left[i]=arr[lo+i];
	}
	for(int i=0;i<second;i++){
		right[i]=arr[mid+1+i];
	}

	int i=0,j=0,k=lo;
	while(i<first&&j<second)
	{
		if(left[i]<=right[j])
		{
			arr[k++]=left[i++];
			
		}
		else if(left[i]>right[j])
		{
			arr[k++]=right[j++];
			
		}
	}
	while(i<first)
	{
		arr[k++]=left[i++];
	}
	while(j<second)
	{
		arr[k++]=right[j++];
	}
}
void mergesort(int arr[],int left,int right)
{
	int mid=left+(right-left)/2;
	//int n=right-left+1;
	if(left<right)
	{
	mergesort(arr,left,mid);
	mergesort(arr,mid+1,right);
	merge(arr,left,mid,right);
    }
}

int main(int argc, char const *argv[])
{
	int arr[]={1,2,-2,-3,-9,11,10,13};
	int n=sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,n);

	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	return 0;
}