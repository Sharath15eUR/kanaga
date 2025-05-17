# Module 1 - Refresh on C, Pointers and Memory Management.

### Q1. C program that represents a calendar for a week. Each day has: dayName (e.g., "Monday"), tasks (array of strings with maximum 3 tasks per day)
**Note:**

**1. Define appropriate structures.**

**2. Allow the user to input tasks for any day.**

**3. Display all tasks grouped by the day.**

The problem statement requires tracking the tasks uploaded for each day. This is carried out using structures in C. The structure designed includes a string for weekday, array of strings to hold the tasks, integer- task count to keep track of the tasks associated with a particular day.
```
typedef struct {
    char day[10];
    char tasks[3][100];
    int task_count;
}daily_task;
```
The `print_tasks()` function takes array of structures as it input and pretty prints the tasks which contain array of tasks associated with a particular day of the week.
```
void print_tasks(daily_task tasks[]){
    printf("\nTasks for the Week :\n");
    printf("--------------------------------------\n");
    
    for(int i=0;i<7;i++){
        printf("------%s------\n",tasks[i].day);
        if(tasks[i].task_count>=1)
            for(int j=0;j<tasks[i].task_count;j++)
                printf("\t- %s\n",tasks[i].tasks[j]);
        else
            printf("\t- No tasks Assigned\n");
        printf("\n");
    }
}
```
The `find_valid_day()` function takes in two parameters, the day which user has inputted and array of structures. By iterating through the array and comparing days of the week with the user input without case sensitivity, the function checks if the input provided by the user is valid or not.
```
int find_valid_day(char* day,daily_task tasks[]){
    for(int i=0;i<7;i++){
        if(strcasecmp(tasks[i].day,day)==0)
            return i;
    }
    return -1;
}
```
This is the array of structures which handle user inputs.
```
    daily_task week_task[7]={
        {"Monday",{},0},
        {"Tuesday",{},0},
        {"Wednesday",{},0},
        {"Thursday",{},0},
        {"Friday",{},0},
        {"Saturday",{},0},
        {"Sunday",{},0}
    };
```
In the menu option, if the user enters 1, it prompts the user to enter a valid day. If the number of tasks in that particular day has not reached its limit, the user can add a task to the day.
```      
        if(option == 1){
            char day[10];
            char dailytask[100];
            
            printf("Enter day : ");
            scanf("%[^\n]s",day);
            getchar();
            int day_index=find_valid_day(day,week_task);
            
            if(day_index!=-1){
                if(week_task[day_index].task_count < 3){
                    printf("\nEnter your Task for %s : ",day);
                    scanf("%[^\n]s",dailytask);
                    strcpy(week_task[day_index].tasks[week_task[day_index].task_count],dailytask);
                    week_task[day_index].task_count++;
                    printf("\nTask Added successfully!\nYou can add %d tasks for %s\n",(3-week_task[day_index].task_count),day);
                }else{
                    printf("Reached limit for maximum number of tasks for %s!!",day);
                }
            }else{
                printf("Invalid Day");
            }
            
        }
```
**EXECUTION :**

![Screenshot (830)](https://github.com/user-attachments/assets/45d365fa-9498-4f7a-9e27-954058d850f7)

![Screenshot (831)](https://github.com/user-attachments/assets/c2406143-0ba2-4562-b0b8-fa1fbd0e7901)

![Screenshot (832)](https://github.com/user-attachments/assets/110aa71c-7f41-47d2-85f4-2d5ed200ae1e)


### Q2. Write a function in C that takes a pointer to an integer array and its size, and then rearranges the array in-place such that all even numbers appear before odd numbers, preserving the original relative order using only pointer arithmetic (no indexing with []).

Dealing with pointers, the `shift()` function takes two pointers left and right with right having the value that needs to be moved to the left. The function carries of the shifting process.
```
void shift(int *left,int *right){
    //Value that needs to be shifted
    int temp=*right;
    //Shifting numbers one position to the right to ensure relativity
    for(int* shifter=right;shifter>left;shifter--)
        *shifter=*(shifter-1);
    //Positioning the even number at its place
    *left=temp;
}
```
The `rearrange()` function targets even numbers and when it encouters an even number, it triggers the shift function.
```
void rearrange(int* ptr,int size){
    int* reader=ptr;
    int* writer=ptr;
    
    while(reader<ptr+size){
        if((*reader) % 2 == 0){
            shift(writer,reader);
            writer++;
        }
        reader++;
    }
}
```
An array is created dynamically and the changes reflected are shown.
```
    int *array=(int *)malloc(size*sizeof(int));
    
    printf("Enter the array elements : ");
    for(int i=0;i<size;i++){
        printf("\nEnter the Element %d : ",i+1);
        scanf("%d",&array[i]);
    }
    
    rearrange(array,size);
    
    printf("\nThe re-arranged array is : \n\n\t\t\t");
    for(int i=0;i<size;i++)
        printf("%d ",array[i]);
```

**EXECUTION :**

![Screenshot (833)](https://github.com/user-attachments/assets/3b5c2afb-e177-47dc-a140-158188cdecb4)

### Q3. You are given a 2D matrix of size n x n where each row and each column is sorted in increasing order. Write a C function to determine whether a given key exists in the matrix using the most efficient approach.
The `find_element()` function takes three arguments, matrix, size of the matrix, key to be searched. Since the matrix is sorted, the matrix is searched from top right to bottom left for better efficiency. 
```
bool find_element(int **matrix,int size,int key){
    int row=0,col=size-1;
    
    while(row<size && col>-1){
        int mid = matrix[row][col];
        if (mid == key)
            return true;
        else if (mid<key)
            row++;
        else
            col--;
    }
    return false;
}
```
**EXECUTION :**

![Screenshot (834)](https://github.com/user-attachments/assets/4a2f0c42-d007-46ca-9deb-ea1ec00b3003)
