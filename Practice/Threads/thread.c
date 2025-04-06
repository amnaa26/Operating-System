#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_OF_THREADS 3
#define size 300

int array[size];

void *array_assignment(void *thread_id){
	long id = (long) thread_id;
	int start = id * (size/NUM_OF_THREADS);
	int end = start + (size/NUM_OF_THREADS);
	
	for(int i = start; i < end; i++){
		array[i] = rand() % 100;
	}
	
	pthread_exit(NULL);
}


int main(){
	pthread_t threads[NUM_OF_THREADS];
	srand(time(NULL));
	long t;
	int threadcreator;
	for(t = 0; t < NUM_OF_THREADS; t++){
		threadcreator = pthread_create(&threads[t], NULL, array_assignment, (void *)t);
		if(threadcreator){
			perror("thread failed");
			exit(-1);
		}
	}
	
	//waiting for all threads to finish
	for(t = 0; t < NUM_OF_THREADS; t++){
		pthread_join(threads[t], NULL);
	}
	
	for(int i = 0; i < 10; i++){
		printf("element %d: %d", i, array[i]);
		printf("\n");
	}
	
	exit(0);
}
