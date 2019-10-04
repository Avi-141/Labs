#include <stdio.h>
#include <stdlib.h>
int comp ;
int probe(int hash[],int a){
	int i = a+1;
	while(i%10 != a){
		if(hash[i] == -1) return i;
		i++;
	}
	return -1;
}
int linearprobe(int hash[],int a,int ele){
	int i = a+1;
	while(i%10 != a){
		if(hash[i] == ele) return i;
		i++;
	}
	return -1;
}
void insert_hash(int a,int hash[]){
	int mod = a%10;
	if(hash[mod]>-1){
		int p = probe(hash,mod);
		if(p>0){
			hash[p] = a;
			printf("%d at idx %d\n",a,p);
		}
	}
	else{
		hash[mod]=a;
		printf("%d at idx %d\n",a,mod);
	}
}
void hashsearch(int a,int hash[]){
	int mod = a%10;
	if(hash[mod]!=a){
		int p = linearprobe(hash,mod,a);
		if(p == -1) printf("not found\n");
		else{
			printf("found at %d\n",p);
		}
	}
	else{
		printf("found at %d\n",mod);
	}
}
int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,32,123,54,3123,54,32};
	int n = sizeof(arr)/sizeof(int);
	int hash[10];
	for(int i =0;i<10;i++)hash[i]=-1;
	insert_hash(1,hash);
	insert_hash(2,hash);
	insert_hash(11,hash);
	hashsearch(1,hash);
	hashsearch(123,hash);
	hashsearch(3123,hash);
	hashsearch(11,hash);
	return 0;
}
