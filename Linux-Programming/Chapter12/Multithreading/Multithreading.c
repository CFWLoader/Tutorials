#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMBER_OF_THREADS 6

void* threadFunction(void* arg);

int main(int argc, char* argv[])
{
	int result = 0;

	pthread_t aThread[NUMBER_OF_THREADS];

	void* threadResult = NULL;

	int lotsOfThreads;

	for(lotsOfThreads = 0;
		lotsOfThreads < NUMBER_OF_THREADS;
		++lotsOfThreads)
	{
		result = pthread_create(&(aThread[lotsOfThreads]), NULL, threadFunction, (void*) &lotsOfThreads);

		if(result != 0){
			perror("Thread creation failed.\n");
			exit(EXIT_FAILURE);
		}

		sleep(1);
	}

	printf("Waiting for threads to finish.\n");

	for(lotsOfThreads = NUMBER_OF_THREADS - 1;
		lotsOfThreads >= 0;
		--lotsOfThreads)
	{
		result = pthread_join(aThread[lotsOfThreads], &threadResult);
		if(result == 0){
			printf("Thread %d joined.\n", lotsOfThreads);
		} else {
			perror("Thread joining failed.");
		}
	}

	printf("All done.\n");

	exit(EXIT_SUCCESS);
}

void* threadFunction(void* arg)
{
	int myNumber = * (int*) arg;

	int randomNumber;

	printf("Thread function is running. Argument was %d.\n", myNumber);

	randomNumber = 1 + (9.0 * rand() / (RAND_MAX + 1.0));

	sleep(randomNumber);

	printf("Bye from %d second.\n", myNumber);

	pthread_exit(NULL);
}
