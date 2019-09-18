#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<unistd.h>
#include<sys/wait.h>
#define fail EXIT_FAILURE
#define success EXIT_SUCCESS
#define outfile STDOUT_FILENO

int main(int argc, char const *argv[])
{
	int fd[2];
	pid_t cpid;
	char buf;
	assert(argc==2);
	if(pipe(fd)==-1)
	{
		perror("cannot create pipe");
	     exit(fail);
	 }

	cpid=fork();
	if(cpid==-1)
	{
		perror("Forking..");
		exit(fail);
	}
	if(cpid==0){ //child reads from pipe
        
        close(fd[1]);//write not being used
        while(read(fd[0],&buf,1)>0)
        {
        	write(outfile,&buf,1);
            write(outfile,"\n",1);
        }
           close(fd[0]); //close read end
          exit(success);
      }
    else{ //parent writes argv[1] to pipe

    	close(fd[0]); //close unused read end
    	write(fd[1],argv[1],strlen(argv[1]));
    	close(fd[1]); // reader will see EOF
    	wait(NULL);
    	exit(success);

     }
}