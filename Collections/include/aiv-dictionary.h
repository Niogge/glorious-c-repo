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
typedef struct{
    dict_node** __hashmap;
} aiv_dict;

aiv_dict* aiv_dict_new();
void aiv_dict_put(aiv_dict* dict, void* key, uint keylen, void* val);


#endif