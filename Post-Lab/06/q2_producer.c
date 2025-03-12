#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
	int fd;
	char buffer[BUFSIZ];
	ssize_t num_bytes;

	mkfifo(FIFO_FILE, 0666);
	fd = open(FIFO_FILE, O_WRONLY);
	if (fd == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	while(1){
		printf("Producer: Enter a message (or 'exit' to quit): ");
		fgets(buffer, BUFSIZ, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';

		num_bytes = write(fd, buffer, strlen(buffer));
		if(num_bytes == 01){
			perror("write");
			exit(EXIT_FAILURE);
		}

		if(strcmp(buffer, "exit") == 0) break;
	}

	close(fd);
	unlink(FIFO_FILE);

	return 0;
}
