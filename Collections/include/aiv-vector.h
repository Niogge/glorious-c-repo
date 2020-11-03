#ifndef AIV_VECTOR_H
#define AIV_VECTOR_H
#include <stdlib.h>

typedef unsigned int uint;

struct _aiv_vector{
    void** __items;
    uint __count;
    uint __capacity;
};

typedef struct _aiv_vector aiv_vector;

aiv_vector* aiv_vector_new();
aiv_vector* aiv_vector_new_with_cap(uint capacity);
void aiv_vector_destroy(aiv_vector* vector);
void aiv_vector_add(aiv_vector* vector, void* item);
void* aiv_vector_at(aiv_vector* vector, uint index);
aiv_vector* aiv_vector_resize(aiv_vector* vector, uint capacity);
void aiv_vector_foreach(aiv_vector* vector, void (*action)(void* elem));
#endif // AIV_VECTOR_H