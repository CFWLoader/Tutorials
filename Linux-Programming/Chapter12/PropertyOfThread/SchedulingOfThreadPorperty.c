#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* threadFunction(void* arg);

char message[] = "Hello World.";

int threadFinished = 0;

int maxPriority;
int minPriority;

struct sched_param schedulingValue;

int main()
{
	int result;

	pthread_t aThread;

	pthread_attr_t threadAttribute;

	result = pthread_attr_init(&threadAttribute);

	if(result != 0){
		perror("Attribute creation failed.");
		exit(EXIT_FAILURE);
	}

	result = pthread_attr_setdetachstate(&threadAttribute, PTHREAD_CREATE_DETACHED);

	if(result != 0){
		perror("Setting detached attribute failed.");
		exit(EXIT_FAILURE);
	}

	//News in here, setting scheduling level.
	result = pthread_attr_setschedpolicy(&threadAttribute, SCHED_OTHER);

	if(result != 0){
		perror("Setting scheduling policy failed.");
		exit(EXIT_FAILURE);
	}

	//Get the range of priority.
	maxPriority = sched_get_priority_max(SCHED_OTHER);
	minPriority = sched_get_priority_min(SCHED_OTHER);

	//Setting the priority.
	schedulingValue.sched_priority = minPriority;

	result = pthread_attr_setschedparam(&threadAttribute, &schedulingValue);

	if(result != 0){
		perror("Setting scheduling priority failed.");
		exit(EXIT_FAILURE);
	}
	//News end.

	result = pthread_create(&aThread, &threadAttribute, threadFunction, (void*) message);

	if(result != 0){
		perror("Thread creation failed.");
		exit(EXIT_FAILURE);
	}

	pthread_attr_destroy(&threadAttribute);			//It's a good habbit that destroy the thread attribute variable immediately after creation of a thread.

	while(!threadFinished)
	{
		printf("Waiting for thread to say it's finished.\n");
		sleep(1);
	}

	printf("Other thread finished, good bye.\n");

	exit(EXIT_SUCCESS);
}

void* threadFunction(void* arg)
{
	printf("threadFunction is running. Argument was %s.\n", (char*)arg);

	sleep(4);

	printf("Second thread setting finished flag, and exiting now.\n");

	threadFinished = 1;

	pthread_exit(NULL);
}
