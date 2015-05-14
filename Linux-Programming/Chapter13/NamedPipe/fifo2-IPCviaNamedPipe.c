#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/myFifo"

int main(int argc, char* argv[])
{
	int result;

	int openMode = 0;

	int i;

	if(argc < 2){
		fprintf(stderr, "Usage: $s <some combination of O_RDONLY O_WRONLY O_NONBLOCK>.\n", *argv);
		exit(EXIT_FAILURE);
	}

	char** argvPtr = argv;

	//Polling for argument values.
	for(i = 1; i < argc; ++i)
	{
		if(strncmp(*(++argvPtr), "O_RDONLY", 8) == 0){	
			openMode |= O_RDONLY;
		}

		if(strncmp(*argvPtr, "O_WRONLY", 8) == 0){
			openMode |= O_WRONLY;
		}

		if(strncmp(*argvPtr, "O_NONBLOCK", 10) == 0){
			openMode |= O_NONBLOCK;
		}

	}

	//Checking existence of file and create file if it's necessary.
	if(access(FIFO_NAME, F_OK) == -1){

		result = mkfifo(FIFO_NAME, 0777);

		if(result != 0){
			fprintf(stderr, "Could not create fifo %s.\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}

	}

	printf("Process %d opening FIFO.\n", getpid());

	result = open(FIFO_NAME, openMode);

	printf("Process %d result %d.\n", getpid(), result);

	sleep(5);

	if(result != -1) close(result);

	printf("Process %d finished.\n", getpid());

	exit(EXIT_SUCCESS);
}
