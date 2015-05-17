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

int main(int argc, char* argv[])
{
	int pipeFd;			//pipe file descriptor.

	int result;

	int openMode = O_RDONLY;

	char buffer[BUFFER_SIZE + 1];

	int bytesRead = 0;

	memset(buffer, '\0', sizeof(buffer));

	printf("Process %d opening FIFO O_RDONLY.\n", getpid());

	pipeFd = open(FIFO_NAME, openMode);

	printf("Process %d result %d.\n", getpid(), pipeFd);

	if(pipeFd != -1){
		do
		{
			result = read(pipeFd, buffer, BUFFER_SIZE);
			bytesRead += result;
		}while(result > 0);

		close(pipeFd);
	} else {
		exit(EXIT_FAILURE);
	}

	printf("Process %d finished, %d bytes read.\n", getpid(), bytesRead);

	exit(EXIT_SUCCESS);
}
