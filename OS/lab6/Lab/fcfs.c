#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
void bubbleSort(int arrival[], int burst[],int priority[],int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
    {
      	for (j = 0; j < n-i-1; j++)
       {
           if (arrival[j] > arrival[j+1])
            { 
             //swap(&arrival[j], &arrival[j+1]);
             int temp1=arrival[j];
             arrival[j]=arrival[j+1];
             arrival[j+1]=temp1;

             int temp2=burst[j];
             burst[j]=burst[j+1];
             burst[j+1]=temp2;
             //swap(&burst[j],&burst[j+1]);
            }
       }
    } 
}
void fcfs(int arrival[],int burst[],int priority[],int n)
{
	int waiting[n];
	int tat[n];
	int finish[n];
	memset(waiting,0,n*sizeof(int));
	memset(tat,0,n*sizeof(int));
    memset(finish,0,n*sizeof(int));
    int tottime=0;
    for(int i=0;i<n;i++)
    {
    	printf("Process [%d] with priority %d is in the queue\n",i+1,priority[i]);
    	if(i==0)
    	{
    		finish[i]=burst[i];
    		tottime+=burst[i];
    		waiting[i]=arrival[i];
    		tat[i]=burst[i]-arrival[i];
    	}
    	else
    	{
    		waiting[i]=tottime-arrival[i];
    		tottime+=burst[i];
    		finish[i]=tottime;
    		tat[i]=burst[i]+waiting[i];
    	}
    	printf("Waiting time = %d  Finish time = %d  Tat = %d\n",waiting[i],finish[i],tat[i]);
    }
   double avgtat=0.0,avgwait=0;
   for(int i=0;i<n;i++)
   {
   	avgwait+=waiting[i];
   	avgtat+=tat[i];
   }
   avgtat=(double)avgtat/(double)n;
   avgwait=(double)avgwait/(double)n;

  printf("Avgwait is %lf, Avg tat is %lf",avgwait,avgtat);
}
int main()
{
	int count,i,j;
	int burst[30],wait[30],priority[30],arrival[30];
	int tot;
	printf("Total processes ?\n");
	scanf("%d",&tot);
	printf("AT BT PRIORITY\n");
	for(count=0;count<tot;count++)
	{
      printf("Process %d\t",count);
      scanf("%d",&arrival[count]);	
      scanf("%d",&burst[count]);
	  scanf("%d",&priority[count]);
     }
    
    bubbleSort(arrival,burst,priority,tot);
    fcfs(arrival,burst,priority,tot);
}