#ifndef AIV_DICT_H
#define AIV_DICT_H
#include "aiv-common.h"
#include <string.h>



typedef struct _aiv_dict_node dict_node;
struct _aiv_dict_node{
    void* key;
    uint keylen;
    void* data;
    dict_node* next;
};
//it's better to use a linked list so we can have better insert and remove, easier than a vector
//we are basically keeping an array of smaller linked lists, so we get the flexibility of a linked list
//but we can easy access elements ALMOST directly with keys (if we have low collisions)
typedef struct{
    dict_node** __hashmap;
} aiv_dict;

_DLL_EXPORT_ aiv_dict* aiv_dict_new();
_DLL_EXPORT_ void aiv_dict_put(aiv_dict* dict, void* key, uint keylen, void* val);


#endif