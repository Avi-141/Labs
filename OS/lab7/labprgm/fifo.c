#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int mkfifo(const char * filename,mode_t mode);
int main(int argc, char const *argv[])
{
	int res = mkfifo("./fifotrans",0666);
	if(res == 0){
		printf("created\n");
	}	
	int fd = open("fifotrans", O_RDWR,0666);
	puts("fifo queue created:");
	pid_t pid = fork();
	if(pid == 0){
		int recv = 0;
		int consumed = 0;
		while(consumed ++ <10 ){
			read(fd,&recv,sizeof(int));
			printf("Consumer consumed:%d\n",recv); 
		}
	}
	else{
		int num;
		int sent=0;
		while(sent++<5){
			scanf("%d",&num);
			write(fd,&num,sizeof(int));
		}
		close(fd);
	}
	return 0;
}