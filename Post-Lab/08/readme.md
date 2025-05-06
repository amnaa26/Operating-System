## Code Workout 01:
a) Parameters are passed to the thread function (runner) via the fourth argument of pthread_create(). The argument must be cast to (void *) when passed, and cast back to the appropriate type inside the thread function.
```.c
int num = 100;
pthread_create(&tid, NULL, runner, (void *)&num);
```
 ``` num ``` is the parameter here which we are passsing in the fourth arguement of pthread_create() so that it will be passed to the runner function.

![image](https://github.com/user-attachments/assets/1687f831-b328-43a2-8683-d6ee039bb621)

 b) ```pthread_attr_init()``` initializes a thread attribute object with default values. This object can later be modified to set custom attributes like stack size, scheduling policy, or detach state
 c) To return a value from a thread, use ```pthread_exit()``` with a pointer, and retrieve it using ```pthread_join()```:
```.c
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
```
![image](https://github.com/user-attachments/assets/ff63e107-4f0e-49e8-9dfd-bcb638d565a3)

## Code Workout 02:
a) 

![image](https://github.com/user-attachments/assets/89e53863-3e1c-4a0c-a1cc-91418f2d753a)

b) Because counter is a shared variable so when p1 is called, counter's value changes and p2 access the counter variable whose value has been changed.

c)
 
![image](https://github.com/user-attachments/assets/7cc4a00e-2805-4b3d-9376-a1447cb8c39e)

Now both the threads uses the local instance of counter which is defined in the runner function, this explains why the  global of counter remains 0 throughout the program.

## Task 1:
(a):

![image](https://github.com/user-attachments/assets/7daacfab-e7c6-4ac7-b737-8a2911694736)

(b):

![image](https://github.com/user-attachments/assets/9e6cf5d1-5a90-40e3-8628-a5d2bee7afa8)

## Task 2:
![image](https://github.com/user-attachments/assets/c679951f-3e5f-42af-bf53-42502b26ca53)

