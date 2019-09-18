#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
struct fib{
	int even;
	int odd;
	int size;
	int evesize;
	int oddsize;
	int * arr;
};
void * fib1(void * param){
	struct fib * ob= (struct fib *)param;
	for(int i = 0;i<ob->size;i++){
		if(i%2==0){
			ob->even+=i;
		}
		else{
			ob->odd+=i;
		}
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
	printf("The Even sum :%d\n",param->even);
	printf("The Odd sum :%d\n",param->odd);
	return 0;
}




