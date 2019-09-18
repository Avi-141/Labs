#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	
	pid_t pid = fork();
	int status;

	if (pid == 0) {
		
		printf("\tIn child process [%d]...\n", getpid());
		sleep(1);

		printf("\tchild [%d] ps output:\n", getpid());
		system("ps");

		sleep(0.5);
		printf("\tChild [%d] quitting.\n", getpid());

		exit(0);
		return 0;

	} else {

		printf("Parent process here [%d]...\n", getpid());
		sleep(0.5);

		printf("parent [%d] ps output:\n", getpid());
		system("ps");
		
		printf("Parent [%d] quitting.\n", getpid());
	}
	return 0;
}