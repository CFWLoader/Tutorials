#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int aSignal)
{
	printf("OUCH! - I got signal %d.\n", aSignal);
}

int main()
{
	void (*signalHandler)(int);

	signalHandler = ouch;

	struct sigaction act;

	act.sa_handler = signalHandler;

	sigemptyset(&act.sa_mask);

	act.sa_flags = 0;

	sigaction(SIGINT, &act, 0);

	while(1) {
		printf("Hello World.\n");
		sleep(1);
	}

}
