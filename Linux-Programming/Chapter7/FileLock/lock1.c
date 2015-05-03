#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(){

	int fileDescriptor;
	int saveErrno;

	fileDescriptor = open ("/tmp/LCK.test", O_RDWR | O_CREAT | O_EXCL, 0444);

	if(fileDescriptor == -1){

		saveErrno = errno;

		printf("Open failed with error %d.\n", saveErrno);
	} else {
		printf("Open succeeded!\n");
	}

	exit(EXIT_SUCCESS);

}
