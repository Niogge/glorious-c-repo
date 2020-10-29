#include <stdio.h>
#include <stdlib.h>

int main(){
    int byte= 2;
    void* mem = malloc(2);

    printf("Heapaddr: 0x%p\n", mem);

    free(mem);

    int n=3;
    int*  numbers = (int*)malloc(n*sizeof(int));
    numbers[0]= 10;
    numbers[1]= 20;
    *(numbers + 2) = 30; //dereferziazione
    for (int i = 0; i < n; i++)
    {
        printf("Num[%d] = %d\n",i,numbers[i]);
    }

    free(numbers);
    
    puts("After free"); //potrebbero rimanere i dati
    for (int i = 0; i < n; i++)
    {
        printf("Num[%d] = %d\n",i,numbers[i]);
    }
}