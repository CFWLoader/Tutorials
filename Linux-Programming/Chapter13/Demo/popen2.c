//This program is the demo that putting data to the input of a pipe.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* writeFilePointer = NULL;

	char buffer[BUFSIZ + 1];

	sprintf(buffer, "Once upon a time, there was a fool.\n");

	writeFilePointer = popen("od -c", "w");

	if(writeFilePointer != NULL){
		fwrite(buffer, sizeof(char), strlen(buffer), writeFilePointer);
		pclose(writeFilePointer);
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE);
}
