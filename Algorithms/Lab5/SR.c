#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

        int in[n+1],out[n+1];
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                in[i]+=a[j][i];
                out[j]+=a[j][i];
            }
        }

}