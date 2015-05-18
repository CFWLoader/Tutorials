#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/shm.h>

#include "SharedMemoryComponent.h"

int main(int argc, char* argv[])
{
	int running = 1;

	void* sharedMemory = (void*) 0;

	SharedData* sharedStuff = 0;

	int shmId;

	srand((unsigned int) getpid());

	shmId = shmget((key_t)1234, sizeof(SharedData), 0666 | IPC_CREAT);

	if(shmId == -1){
		fprintf(stderr, "shmget failed.\n");
		exit(EXIT_FAILURE);
	}

	//Accessing the shared memory.
	sharedMemory = shmat(shmId, (void*)0, 0);

	if(sharedMemory == (void*)-1){
		fprintf(stderr, "shmat failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("Memory attached at %X.\n", (int)sharedMemory);

	//sharedStuff will use part of sharedMemory. You can input data to it util you input "end".
	
	sharedStuff = (SharedData*) sharedMemory;

	sharedStuff->writtenByYou = 0;

	while(running)
	{
		if(sharedStuff->writtenByYou){

			printf("You wrote: %s", sharedStuff->someText);

			sleep(rand() % 4);

			sharedStuff->writtenByYou = 0;

			if(strncmp(sharedStuff->someText, "end", 3) == 0){

				running = 0;

			}

		}
	}

	//Detached memory and unregistered it.
	if(shmdt(sharedMemory) == -1){
		fprintf(stderr, "shmdt failed.\n");
		exit(EXIT_FAILURE);
	}

	if(shmctl(shmId, IPC_RMID, 0) == -1){
		fprintf(stderr, "shmctl(IPC_RMID) failed.\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
