#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cout(int allocation[], int process[], int n)
{
    printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf(" %d \t\t %d \t\t",i+1,process[i]); 
        if (allocation[i] != -1) 
            printf("%d",allocation[i] + 1); 
        else
            printf("Not Allocated"); 
        printf("\n");
    } 
}

void firstFit(int block[], int m,  int process[], int n) 
{ 
    int allocation[n]; 
  
    memset(allocation, -1, sizeof(allocation)); 
   
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        { 
            if (block[j] >= process[i]) 
            {  
                allocation[i] = j; 
                block[j] -= process[i]; 
                break; 
            } 
        } 
    } 
  
    printf("\nFirst fit\n");
    cout(allocation, process, n);
} 

void bestFit(int block[], int m, int process[], int n) 
{ 
    int allocation[n]; 
  
    memset(allocation, -1, sizeof(allocation)); 
  
    for (int i=0; i<n; i++) 
    {  
        int bestIdx = -1; 
        for (int j=0; j<m; j++) 
        { 
            if (block[j] >= process[i]) 
            { 
                if (bestIdx == -1) 
                    bestIdx = j; 
                else if (block[bestIdx] > block[j]) 
                    bestIdx = j; 
            } 
        } 

        if (bestIdx != -1) 
        { 
            allocation[i] = bestIdx; 
            block[bestIdx] -= process[i]; 
        } 
    } 
  
    printf("\nBest fit\n");
    cout(allocation, process, n);
} 

void worstFit(int block[], int m, int process[], int n) 
{ 
    int allocation[n]; 
   
    memset(allocation, -1, sizeof(allocation)); 

    for (int i=0; i<n; i++) 
    { 
        int wstIdx = -1; 
        for (int j=0; j<m; j++) 
        { 
            if (block[j] >= process[i]) 
            { 
                if (wstIdx == -1) 
                    wstIdx = j; 
                else if (block[wstIdx] < block[j]) 
                    wstIdx = j; 
            } 
        } 
 
        if (wstIdx != -1) 
        { 
            allocation[i] = wstIdx; 
            block[wstIdx] -= process[i]; 
        } 
    } 
  
    printf("\nWorst fit\n");
    cout(allocation, process, n);
} 

int main() 
{ 
    int blockSize1[] = {100, 500, 200, 300, 600}; 
    int processSize1[] = {212, 417, 112, 426}; 
    int m = sizeof(blockSize1) / sizeof(blockSize1[0]); 
    int n = sizeof(processSize1) / sizeof(processSize1[0]); 
  
    firstFit(blockSize1, m, processSize1, n);

    int blockSize2[] = {100, 500, 200, 300, 600}; 
    int processSize2[] = {212, 417, 112, 426}; 

    bestFit(blockSize2, m, processSize2, n); 

    int blockSize3[] = {100, 500, 200, 300, 600}; 
    int processSize3[] = {212, 417, 112, 426}; 

    worstFit(blockSize3, m, processSize3, n);

    return 0 ; 
}