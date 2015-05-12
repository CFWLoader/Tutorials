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


