#include<stdio.h>
#include<stdlib.h>
int graph[100][100],queue[100],mark[100];

int n,i,j,front=0,rear=-1;
    void bfs(int v) {
    	for (i=1;i<=n;i++)
    	  if(graph[v][i] && !mark[i])
    	   queue[++rear]=i;
    	if(front<=rear) {
    		mark[queue[front]]=1;
    		bfs(queue[front++]);
    	}
    }
int main(void) 
{

     	int v;
    	printf("\nNo of vertices:");
    	scanf("%d",&n);
    	for (i=1;i<=n;i++) {
    		queue[i]=0;
    		mark[i]=0;
    	}
    	printf("\nEnter matrix`\n");
    	for (i=1;i<=n;i++)
    	  for (j=1;j<=n;j++)
    	   scanf("%d",&graph[i][j]);

    	printf("\nStart BFS from vertex?:");
    	scanf("%d",&v);
    	bfs(v);

        printf("reachable vertices are\n");
    	for (i=1;i<=n;i++)
    	  if(mark[i])
    	   printf("%d\t",i); else
    	   printf("\n Bfs is not possible");
return 0;    
}