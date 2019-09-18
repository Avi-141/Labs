#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

void main()
{	
	int fp = creat("file1.txt", O_RDWR);
	printf("Enter message to be written:\n");
	char c[30];
	gets(c);
	write(fp, c, strlen(c));
}