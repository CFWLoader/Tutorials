#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

const char* testFile = "/tmp/testLock";

int main(){

	int fileDescriptor;
	int byteCount;

	char* byteToWrite = "A";

	struct flock region1;
	struct flock region2;

	int result;

	//Open a file descriptor
	fileDescriptor = open(testFile, O_RDWR | O_CREAT, 0666);

	if(!fileDescriptor){
		fprintf(stderr, "Unable to open %s for read/write.\n", testFile);
		exit(EXIT_FAILURE);
	}

	for(byteCount = 0; byteCount < 100; ++byteCount){
		write(fileDescriptor, byteToWrite, 1);
	}

	//Set 10th-30th byte as region 1 and add a shared lock on it.
	region1.l_type = F_RDLCK;
	region1.l_whence = SEEK_SET;
	region1.l_start = 10;
	region1.l_len = 20;

	//Set 40th-50th byte as region 2 and add an exclusivce lock on it.
	region2.l_type = F_WRLCK;
	region2.l_whence = SEEK_SET;
	region2.l_start = 40;
	region2.l_len = 10;

	//Start locking the file.
	printf("Process %d locking file.\n", getpid());

	result = fcntl(fileDescriptor, F_SETLK, &region1);
	if(result == -1)fprintf(stderr, "Failed to lock region 1.\n");

	result = fcntl(fileDescriptor, F_SETLK, &region2);
	if(result == -1)fprintf(stderr, "Failed to lock region 2.\n");

	sleep(60);

	printf("Process %d closing file.\n", getpid());
	close(fileDescriptor);

	exit(EXIT_SUCCESS);
}
