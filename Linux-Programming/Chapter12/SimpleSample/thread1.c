#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* threadFunction(void* args);

char message[] = "Hello World.";

int main()
{
	int result;

	pthread_t aThread;

	void* threadResult = NULL;

	result = pthread_create(&aThread, NULL, threadFunction, (void*)message);

	if(result != 0){
		perror("Thread creation failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("Waiting for thread to finish.\n");

	result = pthread_join(aThread, &threadResult);

	if(result != 0){
		perror("Thread joind failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined, it returned %s.\n", (char*) threadResult);
	printf("Message is now %s.\n", message);

	exit(EXIT_SUCCESS);

}

void* threadFunction(void* args)
{
	printf("threadFunction is running. Argument was %s.\n", (char*) args);

	sleep(3);

	strcpy(message, "bye!");

	pthread_exit("Thank you for the CPU time.\n");
}
