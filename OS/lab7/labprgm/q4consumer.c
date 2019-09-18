#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#define BUFSIZE 10 //max size of buffer in shared memory
typedef struct{
    int p, c;
    char fruit[BUFSIZE][256];
}shastruc;
int main(){
    pid_t pid;
    int running = 1;
    void *shmaddr = (void *)0;
    shastruc *t;
    int shmid;
    shmid = shmget((key_t)111, sizeof(shastruc), 0666|IPC_CREAT);
    shmaddr = shmat((shmid), (void *)0,0);
    t = (shastruc *)shmaddr;
    while(1){
            while(t->c==t->p){
                printf("BUFFER EMPTY, NOTHING TO CONSUME\n");
                sleep(2);
            }
            t->c = (t->c+1)%BUFSIZE;
            printf("Consuming fruit: %s\t p is at %d c is at %d\n", t->fruit[t->c], t->p, t->c);
    }
}
