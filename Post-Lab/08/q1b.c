#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define THREAD 10
#define THREAD_SIZE (SIZE / THREAD)

float A[SIZE], B[SIZE], C[SIZE] = {0};

void assignValues(float arr[]){
	for(int i = 0; i < SIZE; i++){
		arr[i] = (float) (rand() % 100) / 10;
	}
}

void *runner(void *para){
	int i = (long)para;
	int start = i * THREAD_SIZE;
	int end = start + THREAD_SIZE;
	
	for(int j = start; j < end; j++){
		C[j] += A[j] + B[j];
	}
	
	return NULL;
}


int main(){
	srand(42);
	pthread_t thread[10];
	assignValues(A);
	assignValues(B);
	for(int i = 0; i < THREAD; i++){
		printf("Sum thread : %d\n", i+1);
		pthread_create(&thread[i], NULL, runner, (void *)(long)i);
	}
	
	for(int i = 0; i < THREAD; i++){
		printf("End thread : %d\n", i+1);
		pthread_join(thread[i], NULL);
	}
	
	printf("writing the first initial 50 values: \n");
	for(int i = 0; i < 50; i++){
		printf("%.1f ", C[i]);
	}

}
