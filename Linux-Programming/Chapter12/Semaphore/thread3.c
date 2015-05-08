#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void* threadFunction(void* arg);
sem_t binarySemaphore;

#define WORK_SIZE 1024

char workArea[WORK_SIZE];

int main()
{
	int result;

	pthread_t aThread;

	void* threadResult;

	result = sem_init(&binarySemaphore, 0, 0);

	if(result != 0){
		perror("Semaphore initialization failed.\n");
		exit(EXIT_FAILURE);
	}

	result = pthread_create(&aThread, NULL, threadFunction, NULL);

	if(result != 0){
		perror("Thread creation failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("Input some text. Enter 'end' to finish.\n");
	
	while(strncmp("end", workArea, 3) != 0)
	{
		fgets(workArea, WORK_SIZE, stdin);
		sem_post(&binarySemaphore);
	}

	printf("\nWaiting for thread to finish.\n");

	result = pthread_join(aThread, &threadResult);

	if(result != 0){
		perror("Thread join failed.");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined.\n");

	sem_destroy(&binarySemaphore);

	exit(EXIT_SUCCESS);
}

void* threadFunction(void* arg)
{
	sem_wait(&binarySemaphore);

	while(strncmp("end", workArea, 3) != 0)
	{
		printf("You input %d characters.\n", strlen(workArea) - 1);
		sem_wait(&binarySemaphore);
	}

	pthread_exit(NULL);
}
