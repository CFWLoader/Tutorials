#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/myFifo"

#define BUFFER_SIZE PIPE_BUF

#define TEN_MEG (1024 * 1024 * 10)

int main(int argc, char* argv[])
{
	int pipeFileDescriptor;

	int result;

	int openMode = O_WRONLY;

	int bytesSent = 0;

	char buffer[BUFFER_SIZE + 1];

	//Checking existence of file and create file if it's necessary.
	if(access(FIFO_NAME, F_OK) == -1){

		result = mkfifo(FIFO_NAME, 0777);

		if(result != 0){
			fprintf(stderr, "Could not create fifo %s.\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}

	}

	printf("Process %d opening FIFO O_WRONLY", getpid());

	pipeFileDescriptor = open(FIFO_NAME, openMode);

	printf("Process %d result %d.\n", getpid(), pipeFileDescriptor);

	if(pipeFileDescriptor != -1){

		while(bytesSent < TEN_MEG)
		{
			result = write(pipeFileDescriptor, buffer, BUFFER_SIZE);

			if(result == -1){
				fprintf(stderr, "Write error on pipe.\n");
				exit(EXIT_FAILURE);
			}

			bytesSent += result;
		}

		close(pipeFileDescriptor);
	} else {
		exit(EXIT_FAILURE);
	}

	printf("Process %d finished.\n", getpid());
	
	exit(EXIT_SUCCESS);

}
