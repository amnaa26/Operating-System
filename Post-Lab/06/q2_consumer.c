#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<stdlib.h>

#define FIFO_FILE "/tmp/myfifo"

int main(){
	int fd;
	char buffer[BUFSIZ];
	ssize_t num_bytes;

	fd = open(FIFO_FILE, O_RDONLY);
	if (fd == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	while(1){
		num_bytes = read(fd, buffer, BUFSIZ);
		if(num_bytes == -1){
			perror("read");
			exit(EXIT_FAILURE);
		} else if(num_bytes == 0){
			printf("exiting...\n");
			exit(EXIT_SUCCESS);
		}

		buffer[num_bytes] = '\0';
		printf("Consumer: received message: %s\n", buffer);
	}

	close(fd);

	return 0;
}
