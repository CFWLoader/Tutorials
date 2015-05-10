//This program is the demo that get the output of pipe.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* readFilePointer = NULL;

	char buffer[BUFSIZ + 1];		//Notice this macro.

	int charactersRead;

	memset(buffer, '\0', sizeof(buffer));

	readFilePointer = popen("ps ax", "r");		//Pipe be used as a normal file.

	if(readFilePointer != NULL){
		charactersRead = fread(buffer, sizeof(char), BUFSIZ, readFilePointer);			//Remember the sequence of parameters.

		while(charactersRead > 0){
			buffer[charactersRead - 1] = '\0';
			printf("Reading %d:-\n %s\n", BUFSIZ, buffer);
			
			charactersRead = fread(buffer, sizeof(char), BUFSIZ, readFilePointer);
		}

		pclose(readFilePointer);

		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE);
}
