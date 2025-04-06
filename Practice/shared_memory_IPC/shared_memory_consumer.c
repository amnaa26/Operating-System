#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(){
	const int SIZE = 4096;
	const char *name = "OS MID2";
	int fd;
	char *ptr;
	
	fd = shm_open(name, O_RDWR, 0666);
	if(fd == -1){
		perror("shm_open failed\n");
		return 1;
	}
	
	ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED){
		perror("mmap failed\n");
		close(fd);
		return 1;
	}
	
	printf("%s", ptr); //read from shared memory
	
	munmap(ptr, SIZE); //unmap the shared memory
	close(fd);         //close the file descriptor
	shm_unlink(name);  // remove the shared memory object
	
	//close(fd);
	return 0;
}
