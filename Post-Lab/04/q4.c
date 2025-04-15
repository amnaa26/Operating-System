#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int in_fd, out_fd;
    char buf[1024];
    ssize_t rbytes, wbytes;

    
    in_fd = open("input.txt", O_RDONLY);
    if (in_fd == -1) {
        perror("Can't open input.txt");
        return 1;
    }

    
    out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd == -1) {
        printf("Failed to create output.txt\n");
        close(in_fd);
        return 1;
    }

    
    while ((rbytes = read(in_fd, buf, sizeof(buf))) > 0) {
        wbytes = write(out_fd, buf, rbytes);
        if (wbytes == -1) {
            printf("something went wrong while writing\n");
            close(in_fd);
            close(out_fd);
            return 1;
        }
    }

    if (rbytes == -1) {
        printf("read error occured\n");
        close(in_fd);
        close(out_fd);
        return 1;
    }

    
    close(in_fd);
    close(out_fd);
    printf("Done copying file.\n");
    return 0;
}

