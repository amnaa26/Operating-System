//experiment 6a

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void){
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	int fd[2];
	pid_t pid;

	if(pipe(fd) == -1){
		fprintf(stderr, "Pipe failed");
		return 1;
	}

	pid = fork();
	if(pid < 0){
		fprintf(stderr, "Fork failed");
		return 1;
	}

	if (pid > 0){
		printf("Parent ID: %d\n", getpid());
		close(fd[READ_END]);
		printf("Enter a message: ");
		fgets(write_msg, BUFFER_SIZE, stdin);

		//removing new-line character
		write_msg[strcspn(write_msg, "\n")] = '\0';

		//writing message to pipe
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		close(fd[WRITE_END]);
	} else { //child process
		printf("Child ID: %d\n", getpid());
		usleep(50000);

		close(fd[WRITE_END]);
		
		//reading message from pipe
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("Received: %s\n", read_msg);

		close(fd[READ_END]);
	}

	return 0;
}
