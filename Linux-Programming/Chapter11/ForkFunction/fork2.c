#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	pid_t pid;
	char* message;
	int n;

	printf("fork program starting.\n");
	
	pid = fork();

	switch(pid){
		case -1:
			perror("fork failed.\n");
			exit(EXIT_FAILURE);
		case 0:
			message = "This is the child process.\n";
			n = 3;
			break;
		default:
			message = "This is the parent.\n";
			n = 10;						//Expend this number to make the zombie phenomenon more obvious.
			break;
	}

	for(; n > 0; --n){
		puts(message);
		sleep(1);
	}
	
	exit(EXIT_SUCCESS);
}
