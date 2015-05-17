#include "client.h"
#include <ctype.h>

int main(int argc, char* argv[])
{
	int serverFifoFd, clientFifoFd;

	DataToPass myData;

	int timesToSend;

	char clientFifo[256];

	serverFifoFd = open(SERVER_FIFO_NAME, O_WRONLY);

	if(serverFifoFd == -1){
		fprintf(stderr, "Sorry, no server.\n");
		exit(EXIT_FAILURE);
	}

	myData.clientPid = getpid();

	sprintf(clientFifo, CLIENT_FIFO_NAME, myData.clientPid);

	if(mkfifo(clientFifo, 0777) == -1){
		fprintf(stderr, "Sorry, can't make %s.\n", clientFifo);
		exit(EXIT_FAILURE);
	}

	for(timesToSend = 0; timesToSend < 5; ++timesToSend)
	{
		sprintf(myData.someData, "Hello from %d.\n", myData.clientPid);
		printf("%d sent %s, ", myData.clientPid, myData.someData);

		write(serverFifoFd, &myData, sizeof(myData));

		clientFifoFd = open(clientFifo, O_RDONLY);

		if(clientFifoFd != -1){
			if(read(clientFifoFd, &myData, sizeof(myData))> 0){

				printf("Received: %s.\n", myData.someData);

			}

			close(clientFifoFd);
		}

	}

	close(serverFifoFd);

	unlink(clientFifo);

	exit(EXIT_SUCCESS);

}
