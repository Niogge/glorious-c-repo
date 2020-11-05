#include "aiv-list.h"
#include <stdlib.h>

aiv_list* aiv_list_new(){
    aiv_list* list = (aiv_list*) malloc(sizeof(aiv_list));
    list->__head = NULL;
    list->__tail = NULL;
    return list;
}

void aiv_list_destroy(aiv_list* list){
    aiv_node* each = list->__head;
    while(each){
        aiv_node* next = each->__next;
        free(each);
        each = next;
    }
    free(list);
}


void aiv_list_add(aiv_list* list, void* elem){
    aiv_node* node = (aiv_node*) malloc(sizeof(aiv_node));
    node->__data = elem;
    node->__next = NULL;
    
    if(list->__head == NULL){
        list->__head = node;
        list->__tail = node;
    }
    else{
        list->__tail->__next = node;
        list->__tail = node;
    }

}