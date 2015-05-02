#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static const int A_MEGABYTE = 1024 * 1024;

int main(){

	char* someMemory;

	int megaByte = A_MEGABYTE;
	int exitCode = EXIT_FAILURE;

	someMemory = (char*)malloc(megaByte);

	if(someMemory != NULL){
		sprintf(someMemory, "Hello World\n");
		printf("%s", someMemory);
		exitCode = EXIT_SUCCESS;
	}

	exit(exitCode);
}
