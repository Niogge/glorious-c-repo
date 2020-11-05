#include "aiv-dictionary.h"
#include <stdlib.h>

uint djb33x_hash(void* key, uint keylen){
    int hash = 5381;//seed 
    unsigned char* key_as_num = (unsigned char*)key; //key in byte array
    for (int i = 0; i < keylen; i++)
    {
        hash = ((hash << 5 ) + hash) ^ key_as_num[i]; //lshift = moltiplication
    }
    return hash;
}

aiv_dict* aiv_dict_new(){
    aiv_dict* dict = (aiv_dict*)malloc(sizeof(aiv_dict));
    dict->__hashmap = (dict_node**)calloc(sizeof(void*),1);
    return dict;
}

void aiv_dict_put(aiv_dict* dict, void* key, uint keylen,  void* val){
    uint hash = djb33x_hash(key,keylen);
    uint hash_index= hash%1;
    if(dict->__hashmap[hash_index]==NULL){//hash(key) not present
        dict_node * node = malloc(sizeof(dict_node));
        node->key = malloc(sizeof(keylen));
        memcpy_s(node->key, keylen, key, keylen);
        node->keylen = keylen;
        node->data = val;
        node->next= NULL;
        dict->__hashmap[hash_index] = node;
    }
    else{ //hash(key) exists

    }
}