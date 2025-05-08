## Code Workout 1
#### (a)
![image](https://github.com/user-attachments/assets/6b703373-fc2e-4af3-92cb-091038ad7252)

#### (b)
In the bounded buffer problem, semaphores are introduced to handle synchronization between the producer and consumer threads more effectively, replacing the need for continuous condition checking with ```while``` loops. These semaphores help avoid busy-waiting and ensure that operations occur only when the buffer state allows it.

For the producer, the ```empty``` semaphore is used to track available buffer slots. Before adding an item, the producer calls ```sem_wait(empty)``` to ensure space is available. After inserting the item into the buffer, it signals the presence of new data by calling ```sem_post(full)```.

Similarly, the consumer relies on the ```full``` semaphore to check if the buffer contains any items. It performs ```sem_wait(full)``` before accessing the buffer. Once it consumes an item, it updates the ```empty``` semaphore with ```sem_post(empty)``` to indicate that a slot has been freed.

#### (c)
Adding a delay after the critical section helps prevent threads from executing continuously without pause. Without such delays, both producer and consumer threads may end up running in rapid succession, reducing the opportunity for the other thread to make progress. Introducing a brief delay models real-world systems more realistically, where some processing time typically follows access to shared resources, such as data handling or I/O operations.

## Code Workout 2
#### (a)
![image](https://github.com/user-attachments/assets/8268578e-a24a-4ed1-85e1-9ecf8ff0686e)

#### (b)
![image](https://github.com/user-attachments/assets/98d994f9-ebc3-4975-a12e-bd3c69fce6a8)

#### (d)
(i)
This behavior is managed through the readers_count variable. When at least one reader is active, additional readers are allowed to proceed concurrently. This continues until the last reader finishes, reducing readers_count to zero. At that point, the rw_mutex is released, allowing writers to acquire the lock and perform their operations.

(ii)
The rw_mutex ensures mutual exclusion by preventing simultaneous access from both readers and writers. When a writer attempts to enter the critical section, it waits until rw_mutex is available. During this time, new readers are blocked by the readers_count condition, ensuring the writer can access the shared resource without interference.
