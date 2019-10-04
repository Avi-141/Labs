#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define INT_MAX 9999
void output(int V,int dist[][V]) 
{ 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INT_MAX) 
				printf("%s\t", "X"); 
			else
				printf ("%d\t", dist[i][j]); 
		} 
		printf("\n"); 
	} 
}

void fw(int V,int graph[][V]) { 
	int dist[V][V], i, j, k; 

	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	for (k = 0; k < V; k++) { 
		for (i = 0; i < V; i++) { 
			for (j = 0; j < V; j++) {

				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 
	output(V,dist); 
} 
int main() { 
	int V=4;
	int adjMatrix[V][V];
	/*int adjMatrix[V][V] ={ 
		{	   0, INT_MAX,	  -2, INT_MAX },
		{	   4,	   0,	   3, INT_MAX },
		{ INT_MAX, INT_MAX,	   0,	   2 },
		{ INT_MAX,	  -1, INT_MAX,	   0 } 
	};*/
	printf("Enter 9999 for unreachable nodes\n");
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&adjMatrix[i][j]);
	fw(V,adjMatrix); 
	return 0; 
} 
/* 	{0, 5, INF, 10}, 
	{INF, 0, 3, INF}, 
	{INF, INF, 0, 1}, 
	{INF, INF, INF, 0} */

/* 0 max 3 max 
2 0 max max 
max 7 0 1 
6 max max 0*/