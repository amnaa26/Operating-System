#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *helloWorld(void *var){
	sleep(1);
	printf("hello world\n");
	return NULL;
}

int main(){
	pthread_t thread;
	printf("Before thread\n");
	pthread_create(&thread, NULL, helloWorld, NULL);
	pthread_join(thread, NULL);
	printf("After thread\n");
	
	return 0;
}
