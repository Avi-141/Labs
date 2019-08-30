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
int store[20];
static int idx=1;
void dfs(int v){

       //store[idx++]=v;
    	int i;
    	marked[v]=1;
    	for (i=1;i<=Vert;i++)
    	  if(graph[v][i] && !marked[i]) {
             //store[idx++]=v;
    		///printf("\n%d->%d\n",v,i);
    		dfs(i);
   //         store[idx++]=v;
   //  ?/       store
    	}
   store[idx]=v;
   idx++;
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
        for(i=1;i<=Vert;i++){
            if(!marked[i])
                dfs(i);
        }
    	//dfs(1);

        printf("Topological sort\n");
        for(int i=Vert;i>=1;i--)
            printf("%d\t",store[i]);
return 0;
}
