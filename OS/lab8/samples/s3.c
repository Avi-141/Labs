#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
sem_t semaphore;
int count=0;
void *func1(void* param){
	printf("Thread1\n");
	//count++;
	sem_post(&semaphore);
	//printf("%d",count);
}

void *func2(void*param){
	sem_wait(&semaphore);
	printf("Thread2\n");
	//count++;
	//printf("%d\n",count);
}


int main(){

	pthread_t threads[2];
	sem_init(&semaphore,0,1);
	pthread_create(&threads[0],0,func1,0);
	pthread_create(&threads[1],0,func2,0);
	pthread_join(threads[0],0);
	pthread_join(threads[1],0);
	sem_destroy(&semaphore);
}