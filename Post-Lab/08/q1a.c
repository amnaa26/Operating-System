#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

float A[SIZE], B[SIZE], C[SIZE] = {0};

void assignValues(float arr[]){
	for(int i = 0; i < SIZE; i++){
		arr[i] = (float) (rand() % 100) / 10;
	}
}


int main(){
	srand(42);
	assignValues(A);
	assignValues(B);
	
	for(int i = 0; i < SIZE; i++){
		C[i] = A[i] + B[i];
	}
	printf("Sum completed.\n");
	
	printf("Prinitng the initial 50 values of array C:\n");
	for(int i = 0; i < 50; i++){
		printf("%.1f ", C[i]);
	}
}
