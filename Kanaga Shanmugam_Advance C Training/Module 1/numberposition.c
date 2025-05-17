#include <stdio.h>
#include <stdlib.h>

void shift(int *left,int *right){
    //Value that needs to be shifted
    int temp=*right;
    //Shifting numbers one position to the right to ensure relativity
    for(int* shifter=right;shifter>left;shifter--)
        *shifter=*(shifter-1);
    //Positioning the even number at its place
    *left=temp;
}

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

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    
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
    return 0;
}
