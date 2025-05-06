#include <stdio.h>
#include<pthread.h>
#include <stdlib.h>
 
int sum = 0;

void *runner(void *parameter){
	int i = (*(int*)parameter);
	if (i > 0){
		for(int j = 0; j < i; j++){
			sum += i;
		}
	}
	
	pthread_exit(0);
}


int main(int argc, char *argv[]){
	pthread_t threadID;
	int t;
	printf("Enter an integer: ");
	scanf("%d", &t);
	pthread_create(&threadID, NULL, runner, (void *)&t);
	pthread_join(threadID, NULL);
	printf("Sum: %d\n", sum);
	exit(0);

}

*/
void *runner(void * argc){
	printf("Thread executing...\n");
	pthread_exit((void*)26);
}

int main(){
	void *exit_status;
	pthread_t thread;
	pthread_create(&thread, NULL, runner, NULL);
	pthread_join(thread, &exit_status);
	printf("Thread exited with status: %ld\n", (long)exit_status);
	return 0;
}

*/
