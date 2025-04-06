#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fd;
    char buffer[BUFSIZ];
    ssize_t num_bytes;

    fd = open(FIFO_FILE, O_RDONLY); // Opens named pipe for reading only
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {  // Consumer loop
        num_bytes = read(fd, buffer, BUFSIZ - 1);
        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[num_bytes] = '\0'; // Null-terminate the string
        printf("Consumer received: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    close(fd);  // Closed named pipe
    return 0;
}
