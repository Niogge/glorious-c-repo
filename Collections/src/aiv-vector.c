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

bool aiv_vector_is_empty(aiv_vector* vector){
    if(vector->__count == 0){
        return true;
    }
    return false;
}

void aiv_vector_set(aiv_vector* vector, const uint index, void* elem){
    if(index >= vector->__count) return;
    vector->__items[index] = elem;
}

void aiv_vector_add_all(aiv_vector* vector, aiv_vector* other){

    int n_of_elements = vector->__count + other->__count;
    if((n_of_elements)>= vector->__capacity){
        vector = aiv_vector_resize(vector,(n_of_elements)*2 );
    }

    for (int i = 0; i < other->__count; i++)
    {
        vector->__items[i+vector->__count] = other->__items[i];
        vector->__count++;
    }
    
}

void* aiv_vector_remove_at(aiv_vector* vector, const uint index){
    if(index >= vector->__count) return NULL;
    void * removedItem = vector->__items[index];
    for (int i = index; i < vector->__count-1; i++)
    {
        vector->__items[i] = vector->__items[i+1];
    }
    vector->__count--;
    if(vector->__count < vector->__capacity/2){
        vector = aiv_vector_resize(vector, vector->__capacity/2);
    }
    return removedItem;
    
}

uint aiv_vector_size(aiv_vector* vector){
    return vector->__count;
}

void aiv_vector_insert_at(aiv_vector* vector, const uint index, void* elem){
    if(index >= vector->__count) return;
    vector->__count++;
    if(vector->__count>vector->__capacity){
        vector = aiv_vector_resize(vector, vector->__capacity*2);
    }
    void* old;
    void* new = elem;
    for (int i = index; i < vector->__count; i++)
    {
        old = vector->__items[i];
        vector->__items[i] = new;
        new = old;
    }
    
}

void* aiv_vector_find_one(aiv_vector* vector, bool(*func)(void*)){
    for (int i = 0; i < vector->__count; i++)
    {
        if(func(vector->__items[i])){
            return vector->__items[i];
        }
    }
    return NULL;   
}

aiv_vector* aiv_vector_find_all(aiv_vector* vector, bool(*func)(void*))
{
    aiv_vector* vec = aiv_vector_new();
    for (int i = 0; i < vector->__count; i++)
    {
        if(func(vector->__items[i])){
            aiv_vector_add(vec, vector->__items[i]);
        }
    }
    if(vec->__count >0){
        return vec;
    }
    return NULL;   
}

void aiv_vector_bubble(aiv_vector* vector, int (*comparator)(void*,void*)){
    bool swap = true;
    while(swap == true){
        swap = false;
        for (int i = 0; i < vector->__count-1; i++)
        {
            if(comparator(vector->__items[i], vector->__items[i+1]) == -1){

                void* temp = vector->__items[i];
                vector->__items[i] = vector->__items[i+1];
                vector->__items[i+1] = temp;
                swap = true;                
            }
        }
        
    }
}