#include <stdio.h>

int main(){
    int val =0;
    int* val_ptr = &val;

    printf("val_ptr size: %llu\n", sizeof(int *));

    printf("val_ptr as value= %d\n", val_ptr);
    printf("val_ptr = 0x%p\n", val_ptr);

    printf("val_ptr content: %d\n", *val_ptr);
}