#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* readFilePointer = NULL;

	char buffer[BUFSIZ + 1];

	int charactersRead;

	memset(buffer, '\0', sizeof(buffer));

	readFilePointer = popen("cat popen*.c | wc -l", "r");

	if(readFilePointer != NULL){
		charactersRead = fread(buffer, sizeof(char), BUFSIZ, readFilePointer);

		while(charactersRead > 0)
		{
			buffer[charactersRead - 1] = '\0';
			printf("Reading:\n %s\n", buffer);
			charactersRead = fread(buffer, sizeof(char), BUFSIZ,readFilePointer);
		}

		pclose(readFilePointer);

		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE);

}
