
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>

#define MAX_SECONDS 100

void signal_handler(int sig){
    printf("\n\nReceived interrupt %d..Please continue with execution\n\n",sig);
}

int is_prime(int number){
    //Checks if the received argument is prime
    if(number<=1) return 0;
    if(number==2) return 1;
    for(int j=2;(j*j)<=number;j++)
        if(number%j==0)
            return 0;
    return 1;
}

int* sum_of_n_prime(int n){
    int count=0,i=1;
    //Creates a memory space initialized to 0
    int* answer=(int *)calloc(1,sizeof(int));
    //Checks if a number is prime until `n` prime numbers are found
    while(count<n){
        if(is_prime(i)){
            *answer+=i;
            count++;
        }
        i++;
    }
    return answer;
}

void thread2_func(){
    //Noting down the start time of the thread
    time_t start=time(NULL);
    //Comparing if 100 seconds has passed since thread has been created
    while(time(NULL) - start <MAX_SECONDS){
        printf("Thread 1 is running\n");
        sleep(2);
    }
}

void thread3_func(){
    //Noting down the start time of the thread
    time_t start=time(NULL);
    //Comparing if 100 seconds has passed since thread has been created
    while(time(NULL) - start <MAX_SECONDS){
        printf("Thread 2 is running\n");
        sleep(3);
    }
}

int main(){
    signal(SIGINT,signal_handler);
    signal(SIGTSTP,signal_handler);
    int n;
    int *result;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    result=sum_of_n_prime(n);
    printf("Sum of first %d prime numbers is : %d\n",n,*result);
    
    thread2_func();
    thread3_func();

    //De-allocating the memory dynamically assigned by first thread
    free(result);
    return 0;
}