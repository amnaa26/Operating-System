#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(){
	const int SIZE = 4096; //size of shared memory object
	const char *name = "OS MID2";  //name of shared memory object
	const char *message_0 = "Hello";  //strings written to shared memory
	const char *message_1 = "World";
	
	int fd; //shared memory file descriptor
	char *ptr; //pointer to shared memory object
	fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(fd, SIZE);
	
	ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	//writing to shared memory
	sprintf(ptr, "%s", message_0);
	ptr += strlen(message_0);
	sprintf(ptr, "%s", message_1);
	ptr += strlen(message_1);
	
	*ptr = '\0';
	
	close(fd);
	
	return 0;
}
