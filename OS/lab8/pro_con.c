#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int buf[10],front,rear;
sem_t mutex,full,empty;
void * produce(void *a){
	for(int i =0;i>-1;i++){
		sem_wait(&empty);
		sem_wait(&mutex);
		int c;
		sleep(1);
		printf("Enter item to be produced:%d\n",i);
		buf[(++rear)%10]=i;
		sem_post(&mutex);
		sem_post(&full);
		if(rear == 9){
			printf("Buffer!!!\n");
		}
	}
}
void * consume(void *a){
	int item;
	for(int i=0;i>-1;i++){
		sem_wait(&full);
		sem_wait(&mutex);
		item=buf[(++front)%10];
		printf("Consumed %d\n",item);
		sem_post(&mutex);
		sem_post(&empty);
		int val;
		sem_getvalue(&empty,&val);
		if(val == 0){
			printf("Buffer Empty!!! Kya khau???\n");
		}sleep(1);

	}
}
int main(int argc, char const *argv[])
{
	pthread_t t1,t2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,10);
	pthread_create(&t1,0,produce,0);
	pthread_create(&t2,0,consume,0);
	pthread_join(t1,0);
	pthread_join(t2,0);
	return 0;
}