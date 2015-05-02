//This program try to write the data over the bound of its memory and it will be rejected by system.

#include <stdlib.h>

static const int $1K = 1024;

int main(){

	char* someMemory;

	char* scanPtr;

	someMemory = (char*)malloc($1K);

	if(someMemory == NULL) exit(EXIT_FAILURE);

	scanPtr = someMemory;

	while(1){
		*scanPtr = '\0';
		++scanPtr;
	}

	exit(EXIT_SUCCESS);
}
