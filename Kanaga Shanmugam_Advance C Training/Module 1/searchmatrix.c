
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

int main()
{
    int n,key;
    printf("Enter the size of the 2D matrix : ");
    scanf("%d",&n);
    
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    
    printf("Enter elements of a sorted matrix : \n");
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("\nMatrix[%d][%d] : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\nEnter the key to search in the 2D matrix : ");
    scanf("%d",&key);
    
    if (find_element(matrix,n,key))
        printf("\n%d found in the matrix",key);
    else
        printf("\n%d not found in the matrix",key);
    return 0;
}
