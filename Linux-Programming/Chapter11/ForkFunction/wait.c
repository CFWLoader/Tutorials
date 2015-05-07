#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	pid_t pid;
	char* message;
	int n;
	int exitCode;

	printf("fork program starting.\n");
	
	pid = fork();

	switch(pid){
		case -1:
			perror("fork failed.\n");
			exit(EXIT_FAILURE);
		case 0:
			message = "This is the child process.";
			n = 5;
			exitCode = 37;
			break;
		default:
			message = "This is the parent.";
			n = 3;
			exitCode = 0;
			break;
	}

	for(; n > 0; --n){
		puts(message);
		sleep(1);
	}

	if(pid != 0){
		int stateValue;
		pid_t childPid;

		childPid = wait(&stateValue);

		printf("Child has finished: PID = %d.\n", childPid);

		if(WIFEXITED(stateValue)){
			printf("Child exited with code %d.\n", WEXITSTATUS(stateValue));
		} else {
			printf("Childe terminated abnormally.\n");
		}
	}
	
	exit(exitCode);
}
