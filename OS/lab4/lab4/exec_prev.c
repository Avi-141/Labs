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
		printf("execute binary ./block:\n");
		execl("./block", NULL);
	}
	else
	{
		wait(&status);

		printf("\nBye gm\n");
	}
}