#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

int n;
int min_val = INT_MAX;
int max_val = INT_MIN;
int average = 0;

void *minimum(void * args){
	for(int i = 0; i < n; i++){
		int value = *((int*)args + i);
		if(min_val > value){
			min_val = value;
		}
	}
	
	pthread_exit(NULL);
}

void *maximum(void * args){
	for(int i = 0; i < n; i++){
		int value = *((int*)args + i);
		if(max_val < value){
			max_val = value;
		}
	}
	
	pthread_exit(NULL);
}

void *mean(void * args){
	for(int i = 0; i < n; i++){
		int value = *((int*)args + i);
		average += value;
	}
	
	average = average/n;
	
	pthread_exit(NULL);
}

int main(int argc, char * argv[]){
	 n = argc - 1;
	int *array = malloc(sizeof(int) * n);
	
	for(int i = 0; i < n; i++){
		array[i] = atoi(argv[i+1]);
	}
	
	pthread_t mean_t, max_t, min_t;
	int p1, p2, p3;
	
	p1 = pthread_create(&mean_t, NULL, mean, (void *) array);
	if(p1){
		perror("thread failed");
		exit(1);
	}
	
	p2 = pthread_create(&max_t, NULL, maximum, (void *) array);
	if(p2){
		perror("thread failed");
		exit(1);
	}
	
	p3 = pthread_create(&min_t, NULL, minimum, (void *) array);
	if(p3){
		perror("thread failed");
		exit(1);
	}
	
	pthread_join(mean_t, NULL);
	pthread_join(max_t, NULL);
	pthread_join(min_t, NULL);
	
	printf("The average value is %d", average);
	printf("\nThe minimum value is %d", min_val);
	printf("\nThe maximum value is %d", max_val);
	
	free(array);
	
	return 0;
}
