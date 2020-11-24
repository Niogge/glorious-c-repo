#ifndef STACKI_H
#define STACKI_H
#include <stdlib.h>

typedef unsigned char boolean;

typedef unsigned int uint;
typedef struct{
    int* __data;
    uint __capacity;
    uint __count;
} stacki;

static stacki* stacki_new(uint capacity){
    stacki* s= (stacki*)malloc(sizeof(stacki));
    s->__data = (int*)calloc(capacity,sizeof(int));
    s->__count = 0;
    s->__capacity=capacity;
    return s;
}

static void stacki_free(stacki* s){
    free(s->__data);
    free(s);
}

static boolean stacki_is_empty(stacki* s){
    return s->__count == 0;
}

static void stacki_push(stacki* s, int v){
    s->__data[s->__count++] = v;
}

static int stacki_pop(stacki* s){
    return s->__data[--s->__count];
}
#endif