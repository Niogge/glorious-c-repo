#ifndef AIV_LIST_H
#define AIV_LIST_H

struct _aiv_list_node{
    void* __data;
    struct _aiv_list_node* __next;
};
typedef struct _aiv_list_node aiv_node;


struct _aiv_list{
    aiv_node* __head;
    aiv_node* __tail;
};

typedef struct _aiv_list aiv_list;

aiv_list* aiv_list_new();
void aiv_list_destroy(aiv_list* list);
void aiv_list_add(aiv_list* list, void* elem);
#endif