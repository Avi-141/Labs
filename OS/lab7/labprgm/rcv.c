//IPC rcv.c

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE  128

int ispalin(char str[]) 
{ 
    int lo = 0; 
    int hi= strlen(str) - 1; 
  
    while (hi > lo) 
    { 
        if (str[lo++] != str[hi--]) 
        { 
            printf("%sBhak", str); 
            return -1; 
        } 
    } 
 return 1; 
}
int numpalin(int n){

    int rev=0,rem=0;
    while( n!=0 ){
        rem= n%10;
        rev= rev*+rem;
        n /= 10;
    }
return n;
}
void die(char *s)
{
  perror(s);
  exit(1);
}

typedef struct msgbuf
{
    long    mtype;
    char    mtext[MAXSIZE];
} ;


int main()
{
    int msqid;
    key_t key;
    struct msgbuf rcvbuffer;

    key = 1234;

    if ((msqid = msgget(key, 0666)) < 0)
      die("msgget()");
    if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
      die("msgrcv");

    int ans=numpalin((int)rcvbuffer.mtext);
    if(ans==(int)rcvbuffer.mtext)
        printf("Number is a palindrome\n");
    if(ispalin(rcvbuffer.mtext)==1)
         printf("%s Is a pal", rcvbuffer.mtext);

    printf("%s\n", rcvbuffer.mtext);
    exit(0);
}
