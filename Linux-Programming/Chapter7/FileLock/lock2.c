#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>		//Means file control?
#include <errno.h>

const char* lockFile = "/tmp/LCK.test2";

int main(){

	int fileDescriptor;
	int tries = 10;

	while(tries--){
		fileDescriptor = open(lockFile, O_RDWR | O_CREAT | O_EXCL, 0444);

		if(fileDescriptor == -1){
			printf("%d - Lock already present.\n", getpid());
			sleep(3);
		} else {
			printf("%d - I have exclusive access.\n", getpid());
			sleep(1);
			close(fileDescriptor);
			unlink(lockFile);
		}
		sleep(2);
	}

	exit(EXIT_SUCCESS);
}
