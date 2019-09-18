#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	int status;
	pid_t pid;
	pid=fork();

	if(pid==-1)
	{
		printf("Error child not created\n");

	}
	else if(pid==0)
	{
		printf("CHILDDDDD\n");
		exit(0);
	}
	else {
		wait(&status);
		printf("BAAAP agaya\n");
		printf("Child returned %d\n",status);
	}

}