# Module 2 - Threads and GDB

### Q1. Write a C program to define 3 different threads with the following purposes where N is the input
**Thread A - To run a loop and return the sum of first N prime numbers**

**Thread B & C - should run in parallel. One prints "Thread 1 running" every 2 seconds, and the other prints "Thread 2 running" every 3 seconds for 100 seconds.**

This function accepts a number and checks if it is a prime number or not
```
int is_prime(int number){
    //Checks if the received argument is prime
    if(number<=1) return 0;
    if(number==2) return 1;
    for(int j=2;(j*j)<=number;j++)
        if(number%j==0)
            return 0;
    return 1;
}
```
This function iterates through series of number and simultaneously calculates sum of prime number until it reaches 'n' prime numbers.
```
void* sum_of_n_prime(void* n){
    int limit=*(int *)n,count=0,i=1;
    //Creates a memory space initialized to 0
    int* answer=(int *)calloc(1,sizeof(int));
    //Checks if a number is prime until `n` prime numbers are found
    while(count<limit){
        if(is_prime(i)){
            *answer+=i;
            count++;
        }
        i++;
    }
    return (void*)answer;
}

```
This is one of the two thread functions which prints a particular statement in specified intervals for 100 seconds.
```
void* thread2_func(void* argument){
    //Noting down the start time of the thread
    time_t start=time(NULL);
    //Comparing if 100 seconds has passed since thread has been created
    while(time(NULL) - start <MAX_SECONDS){
        printf("Thread 1 is running\n");
        sleep(2);
    }
    return NULL;
}
```
A thread is created using `pthread_create(Address of Thread, Arguments to it, Function to call upon creation, Arguments to the function)`. The thread created can be joined to the main thread using `pthread_join(Thread,Arguments)`. Pthread stands for Process Thread in this context.

**EXECUTION :**

![Screenshot (827)](https://github.com/user-attachments/assets/8fa7028b-2f80-4587-baa6-3aad6273188d)

### Q2. In the above program, add signal handling for SIGINT (etc) and prevent termination. Convert the above threads to individual functions and note down the time taken and the flow of execution.
The functions related to threads in the above program are converted to simple functions. The execution time can be compared by running the programs using the command `time ./object_file`. By observing the difference, it is clear that by using threads, the [execution time is cut down by almost half](https://github.com/Sharath15eUR/kanaga/blob/main/Kanaga%20Shanmugam_Advance%20C%20Training/Module%202/comparison.txt).

In addition, signals can be caught using the `signal(SIGNAL_TYPE,function_to_handle_signal)` function from the signal.h library file. 

**EXECUTION :**

![Screenshot (828)](https://github.com/user-attachments/assets/5901c301-363d-4197-a13d-a061da589f09)

![Screenshot (829)](https://github.com/user-attachments/assets/df3e6f3d-4443-456c-b86a-7954346b1c8b)

### Q3. Know about the following topics and explore them (Write a note on your understandings)
1. **Child process - fork()**

Fork is a function that creates a child process. If its return value is less than 0 then the execution has failed. If it is greater than 0, then it is associated with the parent. If it is 0, then it is associated with the child that has been created. Forking creates processes with different process ids unlike threads.

2. **Handing common signals**

Signals are the means of communication between processes. There are different types of signals like SIGINT,SIGKILL,SIGSEGV,SIGTSTP and many more. These signals can be handled by using functions. Each signal is associated with a numerical value which is used in various signal handling methods.

3. **Exploring different Kernel crashes**

Kernel crashes, or kernel panics, occur due to fatal system errors like hardware faults, invalid memory access, or buggy drivers. These crashes halt the system and require a reboot. Kernel crashes can be analyzed by viewing the logs (e.g., /var/log/kern.log) and use debugging tools like dmesg or crash to trace the cause and improve kernel stability.

4. **Time complexity**

Time complexity gives the idea of the time taken for execution by a particular algorithm or program. Time complexity is popularly expressed in Big O notation and different types of complexities are O(1), O(logn), O(n logn), O(n^2) etc. Analyzing time complexity is useful to write efficient codes.

5. **Locking mechanism - mutex/spinlock**

Locking mechanisms are used to prevent race conditions when multiple threads access shared resources. A mutex (mutual exclusion) allows only one thread at a time to access a critical section, and it puts other threads to sleep if the lock is already held. A spinlock also prevents multiple threads from entering the critical section, but instead of sleeping, waiting threads keep "spinning" in a loop, checking repeatedly until the lock is available. Spinlocks are faster for short waits, while mutexes are better for longer waits or when context switching is preferred.
