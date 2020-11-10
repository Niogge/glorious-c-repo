#ifndef AIV_VECTOR_H
#define AIV_VECTOR_H
#include <stdlib.h>
#include "aiv-common.h"

struct _aiv_vector{
    void** __items;
    uint __count;
    uint __capacity;
};

typedef struct _aiv_vector aiv_vector;

_DLL_EXPORT_ aiv_vector* aiv_vector_new();
_DLL_EXPORT_ aiv_vector* aiv_vector_new_with_cap(uint capacity);
_DLL_EXPORT_ void aiv_vector_destroy(aiv_vector* vector);
_DLL_EXPORT_ void aiv_vector_add(aiv_vector* vector, void* item);
_DLL_EXPORT_ void* aiv_vector_at(aiv_vector* vector, uint index);
_DLL_EXPORT_ aiv_vector* aiv_vector_resize(aiv_vector* vector, uint capacity);
_DLL_EXPORT_ void aiv_vector_foreach(aiv_vector* vector, void (*action)(void* elem));
_DLL_EXPORT_ bool aiv_vector_is_empty(aiv_vector* vector);
_DLL_EXPORT_ void aiv_vector_set(aiv_vector* vector, const uint index, void* elem);
_DLL_EXPORT_ void aiv_vector_add_all(aiv_vector* vector, aiv_vector* other);
_DLL_EXPORT_ void* aiv_vector_remove_at(aiv_vector* vector, const uint index);
_DLL_EXPORT_ uint aiv_vector_size(aiv_vector* vector);
_DLL_EXPORT_ void aiv_vector_insert_at(aiv_vector* vector, const uint index, void* elem);
_DLL_EXPORT_ void* aiv_vector_find_one(aiv_vector* vector, bool(*func)(void*));
_DLL_EXPORT_ aiv_vector* aiv_vector_find_all(aiv_vector* vector, bool(*func)(void*));
_DLL_EXPORT_ void aiv_vector_bubble(aiv_vector* vector, int (*comparator)(void*,void*));
_DLL_EXPORT_ void aiv_vector_quick(aiv_vector* vector, int (*comparator)(void*,void*));
#endif // AIV_VECTOR_H