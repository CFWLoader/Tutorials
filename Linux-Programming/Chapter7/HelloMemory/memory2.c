#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static const int A_MEGABYTE = 1024 * 1024;

static const int PHYSICAL_MEMORY_MEGS = 1024;

int main(){

	char* someMemory;

	size_t sizeToAllocate = A_MEGABYTE;

	int megsObtained = 0;
	
	while(megsObtained < (PHYSICAL_MEMORY_MEGS * 2)){

		someMemory = (char*)malloc(sizeToAllocate);

		if(someMemory != NULL){
			++megsObtained;

			sprintf(someMemory, "Hello World");

			printf("%s - now allocated %d Megabytes\n", someMemory, megsObtained);

		} else {
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}	
