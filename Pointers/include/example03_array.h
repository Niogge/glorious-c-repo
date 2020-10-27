#include <stdio.h>

void array_as_arg(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d , ", array[i]);
    }
    puts("");
    
}

int main(){
    int array1[3];
    int array2[] = {1,2,3};
    int array3[3] = {1,2,3};

    int*arr_ptr = array3;
    printf("array ptr: 0x%p\n", arr_ptr);

    printf("first: %d\n", *arr_ptr);
    printf("second: %d\n", *(arr_ptr +1 ));
    printf("third: %d\n", *(arr_ptr +2));
    printf("11th?: %d\n", *(arr_ptr +10));
    int size = sizeof(array3)/sizeof(int);
    array_as_arg(array3, size);
}