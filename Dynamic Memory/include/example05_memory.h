#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void printEquals(int r){
    if(r==0){
        printf("so uguali\n");
    }
    else{
        printf("so diverse\n");
    }
}
int main(){
    char* str1 = "Hello";
    char* str2 = "Hello";
    char* str3 = "World";

    int res = memcmp(str1, str2,strlen(str1));
    printEquals(res);
    res = memcmp(str1,str3,strlen(str1));
    printEquals(res);

    ///copia
    int source[10] = {1,2,3,4,5,6,7,8,9,10};
    int dest[5];

    memcpy_s(dest,sizeof(dest),&source[2],sizeof(dest));

    for (int i = 0; i < 5; i++)
    {
        printf("dest[%d] = %d\n",i,dest[i]);
    }
    
}