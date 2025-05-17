#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_SECONDS 100

int is_prime(int number){
    //Checks if the received argument is prime
    if(number<=1) return 0;
    if(number==2) return 1;
    for(int j=2;(j*j)<=number;j++)
        if(number%j==0)
            return 0;
    return 1;
}

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

void* thread3_func(void* argument){
    //Noting down the start time of the thread
    time_t start=time(NULL);
    //Comparing if 100 seconds has passed since thread has been created
    while(time(NULL) - start <MAX_SECONDS){
        printf("Thread 2 is running\n");
        sleep(3);
    }
    return NULL;
}

int main(){
    pthread_t thread1,thread2,thread3;
    int n;
    int *result;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    //Create Thread 1 to calculate sum of first n prime numbers
    pthread_create(&thread1,NULL,sum_of_n_prime,(void *)&n);
    //Join Thread 1 to main thread and print the result
    pthread_join(thread1,(void **)&result);
    printf("Sum of first %d prime numbers is : %d\n",n,*result);
    //Create threads 2 and 3 to run concurrently and perform the specified operations
    pthread_create(&thread2,NULL,thread2_func,NULL);
    pthread_create(&thread3,NULL,thread3_func,NULL);
    //Join the sub threads to the main thread
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    //De-allocating the memory dynamically assigned by first thread
    free(result);
    return 0;
}