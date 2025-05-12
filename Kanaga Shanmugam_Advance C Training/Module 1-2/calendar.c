#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char day[10];
    char tasks[3][100];
    int task_count;
}daily_task;

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

int find_valid_day(char* day,daily_task tasks[]){
    for(int i=0;i<7;i++){
        if(strcasecmp(tasks[i].day,day)==0)
            return i;
    }
    return -1;
}

int main(){
    
    daily_task week_task[7]={
        {"Monday",{},0},
        {"Tuesday",{},0},
        {"Wednesday",{},0},
        {"Thursday",{},0},
        {"Friday",{},0},
        {"Saturday",{},0},
        {"Sunday",{},0}
    };
    
    int option;
    
    do{
        printf("\n1. Add New Task\n2. Display Tasks\n3. Exit\nEnter your choice : ");
        scanf("%d",&option);
        getchar();
        
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
            
        }else if(option == 2){
            print_tasks(week_task);
        }else if(option == 3){
            printf("-----------------------------------------------------------------------------------------------");
            break;
        }
        
        else{
            printf("Invalid Option. Try Again!");
        }
        
    }while(option!=3);
}