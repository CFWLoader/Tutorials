#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*FunctionPointer)(int);

static int alarmFired = 0;

void ding(int aSignal)
{
	alarmFired = 1;
}

//We will send a SIGALRM from son process to parent process.
int main()
{
	pid_t pid;

	FunctionPointer signalHandler = ding;

	printf("Alarm application starting.\n");

	pid = fork();

	switch(pid)
	{
		case -1:
			perror("fork failed.\n");
			exit(EXIT_FAILURE);
		case 0:
			sleep(5);
			kill(getppid(), SIGALRM);
			exit(0);
	}

	//Parent process will be ready for catching SIGALRM via a signal setting.
	printf("waiting for alarm to go off.\n");
	(void)signal(SIGALRM, signalHandler);

	pause();

	if(alarmFired){
		printf("Ding.\n");
	}

	exit(EXIT_SUCCESS);
}
