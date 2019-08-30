#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void checkPartition(int set[], int set_size, int sum) 
{ 
    unsigned int pow_set_size = pow(2, set_size-1) - 1; 
    int counter, j,temp; 
 
    for(counter = 1; counter <= pow_set_size; counter++) {
    	temp = 0;     
	    for(j = 0; j < set_size; j++) {   
	        //and with specific bit 
	        if(counter & (1 << j)) {
	            temp = temp + set[j];
	        }
	    } 
	    if(sum - temp == temp) {
	    	for(j = 0; j < set_size; j++) {    
	    	    if(counter & (1 << j)) {
	    	        printf("%d ",set[j] );
	    	    }
	    	}
	    	printf("and ");
	    	for(j = 0; j < set_size; j++) {    
	    	    if(!(counter & (1 << j))) {
	    	        printf("%d ",set[j] );
	    	    }
	    	}
	    	printf("\n");
	    } 
    } 
} 

int main() {
	int n,i;
	printf("Enter number of elements: \n");
	scanf("%d",&n);
    int arr[n],sum=0;
	for(i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		sum = sum + arr[i];
	}

	if(sum%2 == 1) 
		printf("Sum is odd, cannot be partitioned\n");	
	else
		checkPartition(arr,n,sum);

}