#include <stdio.h>
#include <stdlib.h>


int main(){
    int* num = (int*)calloc(3,sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("Num[%d] = %d\n",i,num[i]);
    }
}