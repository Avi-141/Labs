#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* bool connected()
{
    //for (i=1;i<=Vert;i++) {
        //  if(marked[i])
             //  count++;
        //}
        //if(count==Vert)
          //printf("\Vert Graph is connected"); else
          //printf("\Vert Graph is not connected");
}*/
int graph[20][20],marked[20],Vert;

void dfs(int v){
    	int i;
    	marked[v]=1;
    	for (i=1;i<=Vert;i++)
    	  if(graph[v][i] && !marked[i]) {
    		printf("\n%d->%d",v,i);
    		dfs(i);
    	}
    }

int main(void){
    	
        int i,j,count=0;
    	printf("Enter number of vertices\n:");
    	scanf("%d",&Vert);
    	for (i=1;i<=Vert;i++){
    		marked[i]=0;
    		for (j=1;j<=Vert;j++)
    		   graph[i][j]=0;
    	}
    	printf("Enter the adjacency matrix\n:");
    	for (i=1;i<=Vert;i++)
    	  for (j=1;j<=Vert;j++)
    	   scanf("%d",&graph[i][j]);
    	dfs(1);
return 0;
}
