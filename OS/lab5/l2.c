#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct fib{
	int size;
	int * arr ;
	int sum;
};
void * fib1(void * param){
	struct fib * ob= (struct fib *)param;
	ob->sum = 0;
	for(int i =0;i<ob->size;i++){
		ob->sum+=ob->arr[i];
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
	for(int i =0;i<param->size;i++){
		scanf("%d",&param->arr[i]);
	}
	pthread_create(&thread,0,&fib1,param);
	pthread_join(thread,(void **)&ret);
	printf("The Sum :%d\n",param->sum);
	return 0;
}