#include "client.h"
#include <ctype.h>

int main(int argc, char* argv[])
{
	int serverFifoFd, clientFifoFd;				//Fd = File Descriptor

	DataToPass myData;

	int readResult = -1;

	char clientFifo[256];

	char* tmpCharPtr;

	mkfifo(SERVER_FIFO_NAME, 0777);

	serverFifoFd = open(SERVER_FIFO_NAME, O_RDONLY);

	if(serverFifoFd == -1){
		fprintf(stderr, "Server fifo failure.\n");
		exit(EXIT_FAILURE);
	}

	sleep(10);

	do
	{
		readResult = read(serverFifoFd, &myData, sizeof(myData));
		
		if(readResult > 0){
			tmpCharPtr = myData.someData;

			while(*tmpCharPtr)
			{
				*tmpCharPtr = toupper(*tmpCharPtr);
				++tmpCharPtr;
			}

			sprintf(clientFifo, CLIENT_FIFO_NAME, myData.clientPid);

			clientFifoFd = open(clientFifo, O_WRONLY);

			if(clientFifoFd != -1){
				write(clientFifoFd, &myData, sizeof(myData));
				close(clientFifoFd);
			}
		}
	}while(readResult > 0);

	close(serverFifoFd);

	unlink(SERVER_FIFO_NAME);

	exit(EXIT_SUCCESS);
}
