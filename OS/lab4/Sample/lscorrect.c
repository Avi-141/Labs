#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main()
{
char dirname[10];
DIR*p;
struct dirent *d;
//printf("Enter directory name\n");
//scanf("%s",dirname);
p=opendir(".");
if(p==NULL)
  {
  perror("Cannot find directory");
  exit(-1);
  }
while(d=readdir(p))
{

  if ((strcmp(d->d_name, ".") ==0) || (strcmp(d->d_name, "..") ==0))
  	continue;
  printf("%s\n",d->d_name);
}
}