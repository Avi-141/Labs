#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>

void main()
{
	int status;
	pid_t pid;
	pid = fork();

	if(pid==-1)
		printf("\nERROR child not created");
	else if(pid==0)
	{
		printf("generate random numbers and die .\n");
		for(int i=0;i<4;i++)
			printf("%d\n",i);
	}
	else
	{
		wait(&status);
		printf("Child is deadd.\nThis is the parent.\n");
	}
} 