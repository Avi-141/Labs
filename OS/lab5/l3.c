#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct fib{
	int low;
	int high;
	int * arr;
	int size;
};
int isPrime(int n){
	int flag = 1;
	for(int i = 2;i<=n/2;i++){
		if(n%i==0) {
			//printf("%d\n",n );
			flag =0;
		}
	}
	return flag;
}
void * fib1(void * param){
	struct fib * ob= (struct fib *)param;
	int k = 0;
	for(int i = ob->low;i<=ob->high;i++){
		if(isPrime(i)){
			ob->arr[k++]=i;
		}
	}

}
int main(int argc, char const *argv[])
{
	int * a;
	pthread_t thread;
	int ret;
	struct fib * param = (struct fib * )malloc(sizeof(struct fib));
	printf("Enter the low range:\n");
	scanf("%d",&param->low);
	printf("Enter the high range:\n");
	scanf("%d",&param->high);
	param->size = param->high - param->low;
	param->arr=(int *)calloc(param->size,sizeof(int));
	pthread_create(&thread,0,&fib1,param);
	pthread_join(thread,(void **)&ret);
	printf("The Series :\n");
	for(int i =0;param->arr[i]!=0;i++){
		printf("%d  ",param->arr[i]);
	}
	return 0;
}
