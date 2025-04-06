#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void){
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE];
	
	int fd[2];
	pid_t pid;
	
	if(pipe(fd) == -1){
		perror("pipe failed");
		return 1;
	}
	
	pid = fork();
	if(pid < 0){
		perror("fork failed");
		return 1;
	}
	
	if(pid > 0){  //parent process
		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);  //write(fd[1], buffer, size)
		close(fd[WRITE_END]);
	}
	
	else{      //child process
		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE);    //read(fd[0], buffer, size)
		printf("read: %s", read_msg);
		close(fd[READ_END]);
	}
	
	return 0;
}
