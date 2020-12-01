#include "mylib.h"
#include <stdio.h>

void hello(){
    puts("Helloooo");
}
void helloint(int val){
    printf("Hello int:%d\n",val);
}
void hellostr(const char* val){
    printf("hello %s\n",val);
}
int sum(int v[], int size){
    int sumVal = 0;
    for (int i = 0; i < size; i++)
    {
        sumVal += v[i];
    }
    return sumVal;
}
int sumPair(Pair P){
    return P.a+P.b;
}
int sumPairPtr(Pair *P){
    return P->a+P->b;
}

void sum_out(int a, int b, int * r){
    *r = a+b;
}

char* fixed_str(){
    return "henlo";
}
//Librerie:
//statiche: .lib
//dinamiche: .dll(.lib .def)