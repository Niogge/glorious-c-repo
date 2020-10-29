#include <stdio.h>
#include <stdlib.h>


int main(){
    int* num = (int*)malloc(3*sizeof(int));
    num[0] = 10;
    num[1] = 20;
    num[2] = 30;

    for (int i = 0; i < 3; i++)
    {
        printf("Num[%d] = %d\n",i,num[i]);
    }
    printf("add before: 0x%p\n",num);
    num = (int*)realloc(num,4*sizeof(int));
    printf("add after:  0x%p\n",num);
    num[3] = 420;
    for (int i = 0; i < 4; i++)
    {
        printf("Num[%d] = %d\n",i,num[i]);
    }
}