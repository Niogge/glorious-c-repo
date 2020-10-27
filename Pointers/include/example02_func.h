#include <stdio.h>
int sum(int *a, int *b){
    return *a+*b;
}

void sump(int *a, int *b, int*r){
    *r = *a + *b;
}


int main(){
    int a = 1;
    int b = 2;
    int r;
    sump(&a,&b, &r);
    printf("%d\n", r);
}