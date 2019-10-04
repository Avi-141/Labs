

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
struct maxheap
{
    int size;
    int* array;
}heap;
typedef struct maxheap* maxx;

void Heapify(struct maxheap* maxHeap, int idx)
{
    int largest = idx;  
    int left = (2*idx) + 1;  
    int right = (idx+1)*2; 

    int flag=0,flagg=0,flaggg=0;
    printf("Current root is %d\t",maxHeap->array[largest]);
    printf("\n");
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest]){
        flag=1;
        printf("Left : %d is greater than current\t\n",maxHeap->array[left]);
        largest = left;
    }
    if (right < maxHeap->size &&maxHeap->array[right] > maxHeap->array[largest]){
        flagg=1;
        printf("Right : %d is greater than current\t\n",maxHeap->array[right]);
        largest = right;
    }
    //largest not root
    if (largest != idx)
    {
        flaggg=1;
        printf("Largest is not root...\n");
        int temp=maxHeap->array[largest];
        maxHeap->array[largest]=maxHeap->array[idx];
        maxHeap->array[idx]=temp;
        printf("....Heapifying...\n");
        Heapify(maxHeap, largest);
    }
    if(flag==0&& flagg==0&& flaggg==0){
    printf("Added to heap\n");
   }

}
struct maxheap* buildheap(int *array, int size){
    int i;
    struct maxheap* maxHeap =(struct maxheap*) malloc(sizeof(struct maxheap));
    maxHeap->size = size;  
    maxHeap->array = array;
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        Heapify(maxHeap, i);
    return maxHeap;
}
void heapSort(int* array, int size)
{
    printf("Sorting the Heap in T-1 seconds.....\n" );
    struct maxheap* maxHeap = buildheap(array, size);

    //last=min
    //largest=root;
    //replace largest,min
    while (maxHeap->size > 1)
    {
        int temp=maxHeap->array[0];
        maxHeap->array[0]=maxHeap->array[maxHeap->size - 1];
        maxHeap->array[maxHeap->size-1]=temp;

        --maxHeap->size;
        Heapify(maxHeap, 0);
    }
}

int main()
{
    int n;
    printf("Heap size\t?");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    heapSort(arr, n);

    printf("\nLoading Heap sorted array...\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    return 0;
}

