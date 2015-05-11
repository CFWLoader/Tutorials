#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int dataProcessed;
	int filePipes[2];

	const char someData[] = "123,hahaha";

	char buffer[BUFSIZ + 1];

	memset(buffer, '\0', sizeof(buffer));

	if(pipe(filePipes) == 0){
		dataProcessed = write(filePipes[1], someData, strlen(someData));
		printf("Wrote %d bytes.\n", dataProcessed);
		
		dataProcessed = read(filePipes[0], buffer, BUFSIZ);

		printf("Read %d bytes: %s. \n", dataProcessed, buffer);

		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE);
}
