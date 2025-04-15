#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("fork failed\n");
        return 1;
    }

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        printf("ls command didn't run\n");
        return 1;
    }

    
    wait(NULL);
    printf("done from parent side\n");

    return 0;
}

