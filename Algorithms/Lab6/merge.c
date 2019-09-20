#include<stdio.h>
#include<stdlib.h>

int op = 0;

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int size1 = m - l + 1; 
    int size2 =  r - m; 
  
    
    int L[size1], R[size2]; 
  
    
    for (i = 0; i < size1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < size2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; 
    j = 0;  
    k = l;
    while (i < size1 && j < size2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < size1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < size2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
	op++;
    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
void systemprint(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{     
    int n; int arr[100];
  
  	printf("Enter the number of elements: \n");
  	scanf("%d",&n);

  	printf("Enter the elements: \n");

  	for(int i=0; i<n; i++)
  		scanf("%d",&arr[i]);
    mergeSort(arr, 0, n - 1); 
  
    printf("\nSorted array is \n"); 
    systemprint(arr, n); 

    printf("\nThe opcount is: %d \n",op);
    return 0;
}