#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int dataProcessed;
	int filePipes[2];

	const char someData[] = "123,hahaha";

	//char buffer[BUFSIZ + 1];

	pid_t forkResult;

	//memset(buffer, '\0', sizeof(buffer));

	if(pipe(filePipes) == 0){
		forkResult = fork();

		if(forkResult == -1){
			fprintf(stderr, "Fork failure.");
			exit(EXIT_FAILURE);
		}

		if(forkResult == (pid_t)0){
			close(0);		//Close current stdin to left the file descriptor 0.

			dup(filePipes[0]);	//dup function will require to dispatch the minimal file descriptor number.
						//We will get file descriptor 0 and associate with stdin due to we closed file descriptor 0.
			close(filePipes[0]);	//Close the pipe for new process.

			close(filePipes[1]);	//Son process doesn't need the writatble part of pipe.

			execlp("od", "od", "-c", (char*)0);	//Replace this process with new process.

			exit(EXIT_FAILURE);	//If this clause executed meaning the program failed.
		} else {
			close(filePipes[0]);	//Parent process need only writable part of pipe and we close the readible part.
			
			dataProcessed = write(filePipes[1], someData, strlen(someData));

			close(filePipes[1]);

			printf("%d - wrote %d bytes.\n", getpid(), dataProcessed);
		}
	}

	exit(EXIT_SUCCESS);
}
