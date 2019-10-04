#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	int row;
	int column;	
}search_;

typedef struct {
	int hash;
	int last_index;
	int * values;

}entry;


entry * make_hash(int n){
	entry * ht = (entry *)malloc(sizeof(entry)*10);
	for(int i = 0;i<10;i++){
		ht[i].hash = i;
		ht[i].last_index = 0;
		ht[i].values = (int *)malloc(sizeof(int)*n);
	}
	return ht;
}
void insert(int arr[],int n,entry * ht){
	for(int i = 0;i<n;i++){
		int mod = arr[i]%10;
		ht[mod].values[ht[mod].last_index++] = arr[i];
	}
}
void value(int ele,entry * ht){
		int mod = ele%10;
		ht[mod].values[ht[mod].last_index++] = ele;
}
search_ pos_struct(int ele,entry *ht,int n){
	int hs = ele%10;
	int f = 0;
	search_ a;
	a.row = hs;
	for(int i = 0;i<n;i++){
		if(ht[hs].values[i] == ele ){
			f =1;
			a.column = i;
		}
	}
	if(f == 0){
		a.column = -1;
		return a;
	}
	else{
		return a;
	}
}
int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,32,123,54,3123,54,32};
	int n = sizeof(arr)/sizeof(int);
	entry * ht = make_hash(n);
	insert(arr,n,ht);
	
	search_ pair = pos_struct(54,ht,n);
	search_ pair1=pos_struct(123,ht,n);
	if(pair.column == -1){
		printf("Not found\n");
	}
	else{
		printf("54 Found at %d,%d\n",pair.row,pair.column);
	}
	printf("123 Found at %d,%d\n",pair1.row,pair1.column);
	return 0;
}
