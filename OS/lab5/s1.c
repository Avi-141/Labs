#include<pthread.h>
#include<stdio.h>

void * thread_code(void * param)
{
	printf("In thread code\n");
}
int main(int argc, char const *argv[])
{
	pthread_t thr;
	pthread_create(&thr,0,&thread_code,0);
	printf("In main\n");
	return 0;
}