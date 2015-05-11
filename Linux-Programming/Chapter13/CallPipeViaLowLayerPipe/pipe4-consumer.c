#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int dataProcessed = -1;

	char buffer[BUFSIZ + 1];

	int fileDescriptor;

	memset(buffer, '\0', sizeof(buffer));

	sscanf(argv[1], "%d", &fileDescriptor);

	dataProcessed = read(fileDescriptor, buffer, BUFSIZ);

	printf("%d - read %d bytes: %s.\n", getpid(), dataProcessed, buffer);

	exit(EXIT_SUCCESS);
}
