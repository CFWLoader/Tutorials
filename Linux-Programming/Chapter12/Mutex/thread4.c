#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void* threadFunction(void* arg);
//sem_t binarySemaphore;		//Replace binary semaphore with mutex.
pthread_mutex workMutex;

//#define WORK_SIZE 1024
static const int WORK_SIZE = 1024;

char workArea[WORK_SIZE];
int timeToExit = 0;

int main()
{
	int result;

	pthread_t aThread;

	void* threadResult;

	//result = sem_init(&binarySemaphore, 0, 0);
	result = pthread_mutex_init(&workMutex, NULL);

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
	/*
	while(strncmp("end", workArea, 3) != 0)
	{
		fgets(workArea, WORK_SIZE, stdin);
		sem_post(&binarySemaphore);
	}
	*/
	while(!timeToExit)
	{
		fgets(workArea, WORK_SIEZ, stdin);
		pthread_mutex_unlock(&workMutex);
		while(1){
			pthread_mutex_lock(&work_mutex);
			if(workArea[0] != '\0'){
				pthread_mutex_unlock(&workMutex);
				sleep(1);
			} else {
				break;
			}
		}
	}

	pthread_mutex_unlock(&workMutex);

	printf("\nWaiting for thread to finish.\n");

	result = pthread_join(aThread, &threadResult);

	if(result != 0){
		perror("Thread join failed.");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined.\n");

	//sem_destroy(&binarySemaphore);
	pthread_mutex_destroy(&mutex);

	exit(EXIT_SUCCESS);
}

void* threadFunction(void* arg)
{
	sleep(1);

	pthread_mutex_lock(&workMutex);

	while(strncmp("end", workArea, 3) != 0)
	{
		printf("You input %d characters.\n", strlen(workArea) - 1);

		workArea[0] = '\0';

		pthread_mutex_unlock(&mutex);

		sleep(1);

		pthread_mutex_lock(&workMutex);

		while(workArea[0] == '\0')
		{
			pthread_mutex
	/*
	sem_wait(&binarySemaphore);

	while(strncmp("end", workArea, 3) != 0)
	{
		printf("You input %d characters.\n", strlen(workArea) - 1);
		sem_wait(&binarySemaphore);
	}

	pthread_exit(NULL);
	*/
}
