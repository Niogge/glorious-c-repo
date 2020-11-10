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
        //We need this memcpy because few lines ahead we will do a memcmp.
        //But why? if we just stored the pointer to the key this would need us access
        //the key based on it's addess, which is stuff we cannot control.
        //doing this memcpy we ensure that if we pass an identical object it gets 
        //recognized, no matter where it's stored.
        node->keylen = keylen;
        node->data = val;
        node->next= NULL;
        dict->__hashmap[hash_index] = node;
    }
    else{ //hash(key) exists
        dict_node * currnode = dict->__hashmap[hash_index];
        dict_node * lastnode;
        while(currnode != NULL){
            if(keylen==currnode->keylen){
                if(memcmp(key,currnode->key,keylen)==0){
                    //same key, substitute
                    currnode->data = val;
                    return;
                }
            }
            lastnode = currnode;
            currnode = currnode->next;
        }
        //no key found 
        dict_node * node = malloc(sizeof(dict_node));
        node->key = malloc(sizeof(keylen));
        memcpy_s(node->key, keylen, key, keylen);
        node->keylen = keylen;
        node->data = val;
        node->next= NULL;
        lastnode->next = node;
    }
}