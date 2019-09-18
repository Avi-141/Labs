#include<pthread.h>
#include<stdio.h>


void *thread_code(void * param)
{
	printf("In thread code\n");
}
int main(int argc, char const *argv[])
{
	pthread_t thr;
	pthread_create(&thread,0,&thread_code,0);
	printf("In main thread\n");
	pthread_join(thread,0);
	//dont need to explicitly call exit()
}

//pthread_exit()
//zero or pointer to void to terminate
