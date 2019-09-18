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
		printf("Im the child. I will print alot of numbers before i die.\n");
		while(1)
		{
			printf("%d\n",getpid() );
		}
	}
	else
	{
		printf("\nThis is the parent.\n");
	}
}