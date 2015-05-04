#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

const char* testFile = "/tmp/testLock";

#define SIZE_TO_TRY 3

void showLockInfo(struct flock* toShow);

int main(){

	int fileDescriptor;
	int result;

	struct flock regionToTest;

	int startByte;

	//Open a file descriptor.
	fileDescriptor = open(testFile, O_RDWR | O_CREAT, 0666);

	if(!fileDescriptor){
		fprintf(stderr, "Unable to open %s for read/write.", testFile);
		exit(EXIT_FAILURE);
	}

	//Setting lock region.
	for(startByte = 0; startByte < 99; startByte += SIZE_TO_TRY){
		
		regionToTest.l_type = F_WRLCK;
		regionToTest.l_whence = SEEK_SET;
		regionToTest.l_start = startByte;
		regionToTest.l_len = SIZE_TO_TRY;
		regionToTest.l_pid = -1;

		printf("Testing F_WRLCK on region from %d to %d.\n", startByte, startByte + SIZE_TO_TRY);

		//Start locking.
		result = fcntl(fileDescriptor, F_GETLK, &regionToTest);

		if(result == -1){
			fprintf(stderr, "F_GETLK failed.\n");
			exit(EXIT_FAILURE);
		}

		if(regionToTest.l_pid != -1){
			printf("Lock would failed. F_GETLK returned:\n");
			showLockInfo(&regionToTest);
		} else {
			printf("F_WRLCK - Lock would succeed.\n");
		}

		//Lock the file via shared lock and set the region.
		regionToTest.l_type = F_RDLCK;
		regionToTest.l_whence = SEEK_SET;
		regionToTest.l_start = startByte;
		regionToTest.l_len = SIZE_TO_TRY;
		regionToTest.l_pid = -1;

		printf("Testing F_RDLCK on region from %d to %d.\n", startByte, startByte + SIZE_TO_TRY);

		//Test the lock on the file.
		result = fcntl(fileDescriptor, F_GETLK, &regionToTest);

		if(result == -1){
			fprintf(stderr, "F_GETLK failed.\n");
			exit(EXIT_FAILURE);
		}

		if(regionToTest.l_pid != -1){
			printf("Lock would fail. F_GETLK returned:\n");
			showLockInfo(&regionToTest);
		} else {
			printf("F_RDLCK - Lock would succeed.\n");
		}

	}

	close(fileDescriptor);

	exit(EXIT_SUCCESS);
}

void showLockInfo(struct flock* toShow){
	printf("\tl_type %d, ", toShow->l_type);
	printf("l_whence %d, ", toShow->l_whence);
	printf("l_start %d, ", (int)toShow->l_start);
	printf("l_len %d, ", (int)toShow->l_len);
	printf("l_pid %d\n", toShow->l_pid);
}
