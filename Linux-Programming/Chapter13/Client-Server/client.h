#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SERVER_FIFO_NAME "/tmp/serverFifo"

#define CLIENT_FIFO_NAME "/tmp/client_%d_fifo"

#define BUFFER_SIZE 20

typedef struct {
	pid_t 	clientPid;
	char 	someData[BUFFER_SIZE - 1];
}DataToPass;
