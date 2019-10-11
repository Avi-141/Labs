#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 15
 
typedef struct edge
{
	int u,v,weight;
}edge;
 
typedef struct list_edges
{
	edge data[MAX];
	int total;
}list_edges;
 
list_edges edge_store;
 
int Tree[MAX][MAX],total;
list_edges spanning_tree;
 
void sort();
void out();
void kruskal();
int find(int belongs[],int Vno);
void union_(int belongs[],int child1,int child2);

 
int main()
{
	int i,j,total_cost;
	printf("\nVertices?:");
    scanf("%d",&total);
	printf("\nEnter Tree:");
	
	for(i=0;i<total;i++)
		for(j=0;j<total;j++)
			scanf("%d",&Tree[i][j]);
			
	kruskal();
	out();
}
 
void kruskal()
{
	int belongs[MAX],i,j,childno1,childno2;
	edge_store.total=0;
 
	for(i=1;i<total;i++)
		for(j=0;j<i;j++)
		{
			if(Tree[i][j]!=0)
			{
				edge_store.data[edge_store.total].u=i;
				edge_store.data[edge_store.total].v=j;
				edge_store.data[edge_store.total].weight=Tree[i][j];
				edge_store.total++;
			}
		}
 
	sort();
	
	for(i=0;i<total;i++)
		belongs[i]=i;
	
	spanning_tree.total=0;
	//DSU 
	for(i=0;i<edge_store.total;i++){
		childno1=find(belongs,edge_store.data[i].u);
		childno2=find(belongs,edge_store.data[i].v);
		
		if(childno1!=childno2){
			spanning_tree.data[spanning_tree.total]=edge_store.data[i];
			spanning_tree.total=spanning_tree.total+1;
			union_(belongs,childno1,childno2);
		}
	}
}
 

void union_(int belongs[],int child1,int child2){
	int i;
	for(i=0;i<total;i++)
		if(belongs[i]==child2)
			belongs[i]=child1;
}
int find(int belongs[],int Vno){
	return(belongs[Vno]);
}

 
void sort(){
	int i,j;
	edge temp;
	
	for(i=1;i<edge_store.total;i++)
		for(j=0;j<edge_store.total-1;j++)
			if(edge_store.data[j].weight>edge_store.data[j+1].weight)
			{
				temp=edge_store.data[j];
				edge_store.data[j]=edge_store.data[j+1];
				edge_store.data[j+1]=temp;
			}
}
 
void out()
{
	int i,cost=0;
	
	for(i=0;i<spanning_tree.total;i++)
	{
		printf("\n(%d--%d\t,Edge cost:%d)",spanning_tree.data[i].u,spanning_tree.data[i].v,spanning_tree.data[i].weight);
		cost+=spanning_tree.data[i].weight;
	}
    printf("\n");
	printf("Total Cost of the spanning tree=%d",cost);
}
/*0 2 0 6 0 
  2 0 3 8 5 
  0 3 0 0 7 
  6 8 0 0 9 
  0 5 7 9 0 */
