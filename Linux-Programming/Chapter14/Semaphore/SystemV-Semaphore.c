#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/sem.h>		//Notice that this is not sem.h.

//#include "semun.h"		//In case of you sys/sem.h do not support X/OPEN semun.
//In fact, you have to define the union.
union semun{
	int val;
	struct semid_ds* buf;
	unsigned short* array;
};

//semun is the union for semaphore control function -- semctl.


static int setSemValue(void);
static void deleteSemValue(void);
static int semaphorePost(void);
static int semaphoreWait(void);

static int semId;

int main(int argc, char* argv[])
{
	int i;
	int pauseTime;

	char operation = 'O';						//Operation code.

	srand((unsigned int)getpid());

	semId = semget((key_t)3344, 1, 0666 | IPC_CREAT);		//Second parameter is value of semaphore.

	//Initialize the semaphore.
	if(argc > 1){

		if(!setSemValue()){
			fprintf(stderr, "Failed to initialize semaphore.\n");
			exit(EXIT_FAILURE);
		}

		operation = 'X';

		sleep(2);
	}

	//The following codes will enter and exit critical region 10 times.
	//Every iteration will start with semaphoreWait() to be scheduled by semaphore.
	for(i = 0; i < 10; ++i)
	{
		if(!semaphoreWait()) exit(EXIT_FAILURE);

		printf("%c", operation);

		fflush(stdout);

		pauseTime = rand() % 3;

		sleep(pauseTime);

		printf("%c", operation);

		fflush(stdout);

		//Befor leaving critical region, codes will call semaphore to set the semaphore available
		//and wait for random time to next iteration.

		if(!semaphorePost()) exit(EXIT_FAILURE);

		pauseTime = rand() % 2;

		sleep(pauseTime);
	}

	printf("\n%d - finished.\n", getpid());

	if(argc > 1){
		sleep(10);

		//Remember to destroy the semaphore after the use of it.
		deleteSemValue();
	}

	exit(EXIT_SUCCESS);
}

//This function will initialize semaphore via semctl, SETVAL flag will lead to initialize semaphore value.
static int setSemValue(void)
{
	union semun semUnion;

	semUnion.val = 1;

	if(semctl(semId, 0, SETVAL, semUnion) == -1) return 0;

	return 1;
}

//Flag IPC_RMID will lead semctl to destroy the semaphore.
static void deleteSemValue(void)
{
	union semun semUnion;

	if(semctl(semId, 0, IPC_RMID, semUnion) == -1){
		fprintf(stderr, "Failed to delete semaphore.\n");
	}
}

static int semaphoreWait(void)
{

	struct sembuf semBuffer;

	semBuffer.sem_num = 0;
	semBuffer.sem_op = -1;  /* P() */
	semBuffer.sem_flg = SEM_UNDO;

	if(semop(semId, &semBuffer, 1) == -1){
		fprintf(stderr, "semaphore wait failed.\n");
		return 0;
	}

	return 1;
}

//semBuffer's sem_op will be set value 1 to increase semaphore value.
static int semaphorePost(void)
{

	struct sembuf semBuffer;

	semBuffer.sem_num = 0;
	semBuffer.sem_op = 1;  /* V() */
	semBuffer.sem_flg = SEM_UNDO;

	if(semop(semId, &semBuffer, 1) == -1){
		fprintf(stderr, "semaphore post failed.\n");
		return 0;
	}

	return 1;
}
