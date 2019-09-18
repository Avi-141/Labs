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
		for(int i=0;i<5;i++)
			printf("%d\n",i);
		printf("The child pid is %d\n", getpid());
	}
	else
	{
		wait(&status);
		printf("The child has died.\nThis is the parent.\n");
		printf("The parent pid is %d\n", getpid());
	}
} 