#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int concat(int a, int b){
    char buffer[40];
    sprintf(buffer,"%d%d",a,b);
    return atoi(buffer);
}

int ** makeMatrix(int n, int m){
    int** matrix;

    matrix = (int **)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        *(matrix + i) = (int*)malloc(m*sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(*(matrix+i)+j) = concat(i +1 ,j);
        }
    }
    return matrix;
}

void clearMatrix(int*** matrixPointer,int n, int m, int clearValue){
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < m; j++)
       {
          *(*(*(matrixPointer)+i)+j) =clearValue;
       }
       
    }
    
}
int main(){

    int n = 3;
    int m = 8;
    int** matrix = makeMatrix(n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        puts("");
    }
    puts("");
    clearMatrix(&matrix,n,m, -420);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        puts("");
    }

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    

    
    
    
    // puts("-------Other Method-------");
    // int* noobmatrix = (int*) malloc(n*m*sizeof(int));
    // for (int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j<m;j++){
    //         int index = i * m + j;
    //         noobmatrix[index] = concat(i+1,j);
    //         printf("%d\t",noobmatrix[index]);
    //     }
    //     puts("");
    // }
    
}