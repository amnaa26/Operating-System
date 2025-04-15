#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t copied_process = fork();

	if (copied_process == -1) {
		printf("process1 failed to fork\n");
		return 1;
	}

	if (copied_process == 0) {
		printf("process id: %d\n", getpid());
		return 0;
	}

	pid_t copied_process2 = fork();

	if (copied_process2 == -1) {
		printf("process2 failed to fork\n");
		return 1;
	}

	if (copied_process2 == 0) {
		printf("parent process id: %d\n", getppid());
		return 1;
	}

	wait(NULL);
	wait(NULL);
	printf("terminating parent process\n");

	return 0;
}
