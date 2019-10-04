#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int n) {
	int i;
	printf("\n");
	for (i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void swap (int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void shiftUp (int A[], int start, int end) {
	int c = end;
	while (c > start) {
		int p = c/2;
		if (A[p] < A[c]) {
			swap(A + p, A + c);
			c = p;
		} else {
			return;
		}
	}
}

void heapify (int A[], int count) {
	int end = 1;
	while (end <= count) {
		shiftUp(A, 1, end);
		end += 1;
	}
}

void buildHeap (int A[], int n) {
	int i;
	for (i = 2; i <= n; ++i) {
		heapify(A, i);
	}
}

void heapSort (int A[], int n) {
	heapify(A, n);
	int end = n;
	while (end > 1) {
		swap(A + end, A + 1);
		end -= 1;
		heapify(A, end);
	}
}

int * inputAHeap (int *size) {
	printf("\n\tEnter number of elements in the heap: ");
	scanf(" %d", size);
	int n = *size;
	int i;
	int *arr = (int *)calloc(n+1, sizeof(int));
	printf("\tEnter %d elements: ", n);
	for (i = 1; i <= n; ++i) {
		scanf(" %d", (arr+i));
		if (i > 1)
			heapify(arr, i);
	}
	return arr;
}

#pragma mark - main

int main (int argc, char const * argv []) {

	
}