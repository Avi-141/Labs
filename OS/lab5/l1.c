
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct fib{
	int size;
	int * arr ;
};
void * fib1(void * param){
	struct fib * ob= (struct fib *)param;
	int n=0,m=1;
	int c = 0;
	ob->arr[0]=0;
	ob->arr[1]=1;
	for(int i = 2;i<=ob->size;i++){
		ob->arr[i]=ob->arr[i-1]+ob->arr[i-2];
	}
}
int main(int argc, char const *argv[])
{
	int * a;
	pthread_t thread;
	int ret;
	struct fib * param = (struct fib * )malloc(sizeof(struct fib));
	printf("Enter the number:\n");
	scanf("%d",&param->size);
	param->arr=(int *)calloc(param->size,sizeof(int));
	pthread_create(&thread,0,&fib1,param);
	pthread_join(thread,(void **)&ret);
	printf("The Series:\n");
	for(int i =0;i<param->size;i++){
		printf("%d  ",param->arr[i]);
	}
	return 0;
}

