#include<stdio.h> 
#include<stdlib.h> 
#include <sys/types.h> 
#include<unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"Fork failed");
		exit(0);
	}
	else if(pid==0)
	{
      execlp("/bin/ls","ls",NULL);
	}
	else{
		wait(NULL);
		printf("CHIld complete");
		exit(0);
	}
	
	return 0;
}