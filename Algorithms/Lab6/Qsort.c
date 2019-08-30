#include<stdio.h>
#include<stdlib.h>
int partition(int[],int,int);
void swap(int *a, int*b){
	int c= *a;
	*a = *b;
	*b = c;
}
void QSort(int arr[], int l, int r){
	if(l<r){
		int p = partition(arr, l, r);
		QSort(arr, l, p-1);
		QSort(arr, p+1, r);
	}

}
int partition(int arr[], int l, int r){
	int p = arr[l];
	int i = l;
	int j = r;
	while(i<j){
		while(arr[i]<=p&&i<r) i++;
		while(arr[j]>p&&j>=l) j--;
		swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[j]);
	swap(&arr[l], &arr[j]);
	return j;
}
int main(){
	int arr[] = {3,5,8,4,1};

	QSort(arr, 0, 5);
	for(int i = 0; i<5;i++){
		printf("%d\t",arr[i]);
	}
}