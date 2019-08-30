#include<stdio.h>
#include<stdlib.h>

  
void subsetSum(int arr[], int n) 
{ 
    int total = 1<<n; 
  
    for (int i=0; i<total; i++) 
    { 
        int sum = 0; 
  
        // Consider binary reprsentation of 
        // current i to decide which elements 
        // to pick. 
        for (int j=0; j<n; j++) 
            if (i & (1<<j)) 
                sum += arr[j]; 
  
        printf("Sum is %d\n",sum); 
    } 
}

int main(void)
{
    int n;
    printf("Enter total ele\n");
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);

    subsetSum(arr,n);
}