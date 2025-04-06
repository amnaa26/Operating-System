#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"

int main(){
	int fd;
	char buffer[BUFSIZ];
	ssize_t num_bytes;
	
	mkfifo(FIFO_FILE, 0666);  //created named pipe 
	fd = open(FIFO_FILE, O_WRONLY); //opens named pipe for writing only
	if(fd == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	while(1){  //producer loop
		printf("Producer:\nEnter a messgae(or 'exit' to quit): ");
		fgets(buffer, BUFSIZ, stdin);
		num_bytes = write(fd, buffer, strlen(buffer));
		if(num_bytes == -1){
			perror("write");
			exit(EXIT_FAILURE);
		}
		
		if(strncmp(buffer, "exit", 4) == 0){
			break;
		}
	}
	
	close(fd);  //closed named pipe
	unlink(FIFO_FILE);
	
	return 0;
}
