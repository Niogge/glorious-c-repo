#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int* num = (int*)malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("Num[%d] = %d\n",i,num[i]);
    }
    memset(num,49,3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("Num[%d] = %c\n",i,num[i]); //%c. occhio.
    }
    free(num);
}