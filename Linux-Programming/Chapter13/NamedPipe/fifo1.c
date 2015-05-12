//This program is to create a named pipe.
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	int result = mkfifo("/tmp/myFifo", 0777);

	if(result == 0) printf("FIFO created.\n");

	exit(EXIT_SUCCESS);
}
