#include "aiv-vector.h"

aiv_vector* aiv_vector_new(){
    return aiv_vector_new_with_cap(10);
}
aiv_vector* aiv_vector_new_with_cap(uint capacity){
    aiv_vector* vector = (aiv_vector*)malloc(sizeof(aiv_vector));
    if(vector == NULL) return NULL;
    vector->__count = 0;
    vector->__capacity = capacity;
    vector->__items = malloc(vector->__capacity * sizeof(void*));
    if(vector->__items == NULL) return NULL;
    return vector;
}
void aiv_vector_destroy(aiv_vector* vector){
    vector->__count = 0;
    free(vector->__items);
    free(vector);
}

void aiv_vector_add(aiv_vector* vector, void* item){

    if(vector->__count == vector->__capacity){
        aiv_vector_resize(vector, vector->__capacity * 2);
    }
    int curr_index = vector->__count;
    vector->__items[curr_index] = item;

    vector->__count++;
}
void* aiv_vector_at(aiv_vector* vector, uint index){
    if(index >= vector->__count){
        return NULL;
    }
    return vector->__items[index];
}

aiv_vector*  aiv_vector_resize(aiv_vector* vector, uint capacity){
    void* ptr = realloc(vector->__items, capacity * sizeof(void*));
    if(ptr == NULL) return NULL;
    vector->__items = ptr;
    vector->__capacity = capacity;
    return vector;
}

void aiv_vector_foreach(aiv_vector* vector, void (*action)(void* elem))
{
    for (int i = 0; i < vector->__count; i++)
    {
        action(vector->__items[i]);
    }
    
}