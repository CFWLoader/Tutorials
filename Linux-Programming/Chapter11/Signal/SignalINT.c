#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int aSignal)
{
	printf("OUCH! - I got signal %d.\n", aSignal);
	(void) signal(SIGINT, SIG_DFL);
}

int main()
{
	void (*signalHandler)(int);

	signalHandler = ouch;

	(void) signal(SIGINT, signalHandler);

	while(1) {
		printf("Hello World.\n");
		sleep(1);
	}

}
