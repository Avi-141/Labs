#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void bestfit(int pr[],int par[],int prs,int pars){
    printf("BEST FIT\n");

	int alloc[prs];
	memset(alloc,-1,sizeof(int));
	for (int i=0; i<prs; i++){
        int idx = -1; 
		for (int j=0; j<pars; j++){ 
			if (par[j] >= pr[i]) { 
				if (idx == -1) 
					idx = j; 
				else if (par[idx] > par[j]) 
					idx = j; 
			} 
		} 

		if (idx != -1) { 
			alloc[i] = idx; 
			par[idx] -= pr[i]; 
		}
	}
	printf("\n#.\tSize\tBlock\n");
	for(int i=0;i<prs;i++){
		printf("P[%d]\t%d\t",i+1,pr[i]);
	   if(alloc[i]!=-1){
	   	  printf("%d\t",alloc[i]+1);
	   	  printf("\n");
	   }
	   	else printf("X");
	   printf("\n");
	} 
}
void firstfit(int pr[],int par[],int prs,int pars){
	 printf("FIRST FIT\n");

	int alloc[prs];
	memset(alloc,-1,sizeof(alloc));
	int vis[pars];
	memset(vis,-1,sizeof(vis));

	for(int i=0;i<prs;i++){
		//printf("%d",pr[i]);

		for(int j=0;j<pars;j++){
		   if(par[j]>=pr[i]){
		   	alloc[i]=j;
		   	par[j]=par[j]-pr[i];
		   	break;
		   	//vis[j]=1;
		   	//printf("%d %d %d %d \n",i,j,par[j],pr[i]);	  
		   }	
		}
	}
   	printf("\n#.\tSize\tBlock\n");
    for(int i=0;i<prs;i++){
    	printf("P[%d]\t%d\t",i+1,pr[i]);
    	if(alloc[i]!=-1){
    		printf("%d\t",alloc[i]+1);
    		printf("\n");
    	}
    	else printf("X\n");
    	printf("\n");

	}
}
void worstfit(int pr[],int par[],int prs,int pars){
    printf("WORST FIT\n");
	int alloc[prs];
	memset(alloc,-1,sizeof(int));
	for (int i=0; i<prs; i++){
        int idx = -1; 
		for (int j=0; j<pars; j++){ 
			if (par[j] >= pr[i]) { 
				if (idx == -1) 
					idx = j; 
				else if (par[idx]<par[j]) 
					idx = j; 
			} 
		} 

		if (idx != -1) { 
			alloc[i] = idx; 
			par[idx] -= pr[i]; 
		}
	}
	printf("\n#.\tSize\tBlock\n");
	for(int i=0;i<prs;i++){
		printf("P[%d]\t%d\t",i+1,pr[i]);
	   if(alloc[i]!=-1){
	   	  printf("%d\t",alloc[i]+1);
	   	  printf("\n");
	   }
	   	else printf("X");
	   printf("\n");
	} 
}

int main(){

	int processes[]={212,417,112,426};
	int partition[]={100,500,200,300,600};
	int fp[]={212,417,112,426};
	int fpar[]={100,500,200,300,600};
	int wp[]={212,417,112,426};
	int wpar[]={100,500,200,300,600};
    int n=sizeof(processes)/sizeof(processes[0]);
    int m=sizeof(partition)/sizeof(partition[0]);
    bestfit(processes,partition,n,m);
    firstfit(fp,fpar,n,m);
    worstfit(wp,wpar,n,m);


}