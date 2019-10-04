#include<stdio.h> 
#include<stdlib.h>
#include<string.h>


void systemprint(int V,int possible[][V]) 
{ 
	printf ("Transitive Closure\n"); 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
			printf ("%d ", possible[i][j]); 
		printf("\n"); 
	} 
} 

void transitiveClosure(int V,int graph[][V]){ 
	
	int possible[V][V], i, j, k; 

	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			possible[i][j] = graph[i][j]; 

	for (k = 0; k < V; k++) 
	{ 
		for (i = 0; i < V; i++) 
		{ 
		
			for (j = 0; j < V; j++) 
			{ 
			
				possible[i][j] = possible[i][j] || (possible[i][k] && possible[k][j]); 
			} 
		} 
	} 

	systemprint(V,possible); 
} 


int main() 
{ 
	int V=4;
	int graph[V][V];
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&graph[i][j]);

	transitiveClosure(V,graph); 
	return 0; 
} 
