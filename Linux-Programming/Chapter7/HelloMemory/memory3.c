#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static const int $1K = 1024;

int main(){
	char* someMemory;

	int sizeToAllocate = $1K;

	int megsObtained = 0;

	int ksObtained = 0;

	while(1){
		for(ksObtained = 0; keObtained < 1024; ++ksObtained){
			someMemory = (char*)malloc(sizeToAllocate);
			if(someMemory == NULL) exit(EXIT_FAILURE);
			sprintf(someMemory, "Hello World");
		}
		++megsObtained;
		printf("Now allocated %d Megabytes\n", megsObtained);
	}

	exit(EXIT_SUCCESS);
}

