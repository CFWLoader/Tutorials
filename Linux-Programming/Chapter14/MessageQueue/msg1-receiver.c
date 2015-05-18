#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/msg.h>

typedef struct {
	long int myMessageType;
	char someText[BUFSIZ];
} MyMessage;

int main(int argc, char* argv[])
{
	int running = 1;

	int msgId;

	MyMessage data;

	long int msgToReceive = 0;

	msgId = msgget((key_t)1234, 0666 | IPC_CREAT);

	//Establish the queue.
	if(msgId == -1){
		fprintf(stderr, "msgget failed with error: %d.\n", errno);
		exit(EXIT_FAILURE);
	}

	//Getting the message util getting "end".
	
	while(running)
	{
		if(msgrcv(msgId, (void*)&data, BUFSIZ, msgToReceive, 0) == -1){
			fprintf(stderr, "msgrcv failed with error: %d.\n", errno);
			exit(EXIT_FAILURE);
		}

		printf("You wrote: %s", data.someText);

		if(strncmp(data.someText, "end", 3) == 0){
			running = 0;
		}
	}

	if(msgctl(msgId, IPC_RMID, 0) == -1){
		fprintf(stderr, "msgctl(RMID) failed.\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
