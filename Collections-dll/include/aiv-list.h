#ifndef AIV_LIST_H
#define AIV_LIST_H
#include "aiv-common.h"
struct _aiv_list_node{
    void* __data;
    struct _aiv_list_node* __next;
    struct _aiv_list_node* __previous;
};
typedef struct _aiv_list_node aiv_node;


struct _aiv_list{
    aiv_node* __head;
    aiv_node* __tail;
    uint __count;
};

typedef struct _aiv_list aiv_list;

_DLL_EXPORT_ aiv_list* aiv_list_new();
_DLL_EXPORT_ void aiv_list_destroy(aiv_list* list);
_DLL_EXPORT_ void aiv_list_add(aiv_list* list, void* elem);
_DLL_EXPORT_ bool aiv_list_is_empty(aiv_list* list);
_DLL_EXPORT_ uint aiv_list_size(aiv_list* list);
_DLL_EXPORT_ void* aiv_list_item_at(aiv_list* list, uint index);
_DLL_EXPORT_ void aiv_list_add_item_at(aiv_list* list, void* elem, uint index);
_DLL_EXPORT_ void aiv_list_remove(aiv_list* list, void* elem);
_DLL_EXPORT_ void aiv_list_remove_at(aiv_list* list, const uint index);
_DLL_EXPORT_ bool aiv_list_contains(aiv_list* list, void* elem);
_DLL_EXPORT_ int aiv_list_index_of(aiv_list* list, void* elem);
#endif