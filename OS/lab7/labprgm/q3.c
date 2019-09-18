#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> // for permission bits
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZ 2
#define SIZE 2048
struct shared_use_st{
	int wrmsg;
	char text[SIZE];
};
/*
struct shmid_ds{
	udi_t shm_perm.uid;
	uid_t shm_perm.gid;
	mode_t shm_perm.mode;
}*/

void nextalpha(char * letter) {
	char *next = (char *)calloc(2, sizeof(char));
	next[1] = '\0';
	if (*letter == 'Z')
		next[0] = 'a';
	else if (*letter == 'z')
		next[0] = 'A';
	else
		next[0] = *letter + 1;
	*letter = *next;
}

int main(){
    //IPC_PRIVATE, SIZE, S_IRUSR | S_IWUSR
    struct shared_use_st *shared_stuff;
	int segment_id = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);

	char *shmem = (char *)shmat(segment_id, NULL, 0);
	*shmem = '\0';
     pid_t pid;
     int i;
     *shmem = 'A';

  for(i = 0; i <9; ++i){
     pid = fork();
      if (pid == 0) {
       while (*shmem == '\0');
         nextalpha(shmem);
          exit(0);
      } 
      else{
         printf("%s -> ", shmem);
		  wait(NULL);
         printf("%s\n", shmem);
     }
    }
    shmdt(shmem);
}


