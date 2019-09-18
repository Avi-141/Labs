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
    shmaddr = shmat((shmid), (void *)0, 0);
    t = (shastruc *)shmaddr;
    t->p = 0;//run producer first!
    t->c = 0;
    char f[256];
    while(1){
            while((t->p+1)%BUFSIZE==t->c){
                printf("BUFFER FULL, CANNOT PRODUCE.\n");
                sleep(3);//wait for consumer to consume
            }
            printf("Enter fruit(0 to exit)\n");
            fgets(f, 255, stdin);
            if(f[0]=='0')
            break;
            t->p = (t->p+1)%BUFSIZE;
            memcpy(t->fruit[t->p], f, strlen(f));
    }
    shmdt(shmaddr);//detach (only producer can delete shared memory)
    shmctl(shmid, IPC_RMID, 0);//delete shared mem
    
}