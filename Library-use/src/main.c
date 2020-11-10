#include <aiv-vector.h>
#include <stdio.h>
int main(){
    aiv_vector* vect = aiv_vector_new();
    int value = 20;
    aiv_vector_add(vect, &value);
    printf("%d\n", *(int*)aiv_vector_at(vect,0));
}