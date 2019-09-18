#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	char *message;
	int num;
	printf("Fork program starting\n");
	pid=fork();

	switch(pid)
	{
		case -1: 
		     perror("failed");
		     exit(-1);
		case 0:
		message="This is the child";
		num=5;
		break;

	    default: 
	         message="This is the parent";
	         num=6;
	         break;

	}
	for(;num>0;num--)
	{
		puts(message);
		sleep(0.3);
	}
	exit(0);
	return 0;
}