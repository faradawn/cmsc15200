#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>

// part2: large numbers 

// [helper function: make double linked list]
dll_intlist* make_dll(int val, dll_intlist* prev, dll_intlist* next){
    dll_intlist* new_unit = (dll_intlist*)malloc(sizeof(dll_intlist));
    if (new_unit == NULL){
        fprintf(stderr, "error making new dll");
        exit(1);
    }
    new_unit->val = val;
    new_unit->prev = prev;
    new_unit->next = next;
    return new_unit;
}

// [helper function: show the double linked list]
void show_dll(dll_intlist* lst) {
    dll_intlist* index = lst;
    while(index != NULL){
        printf("%d", index->val);
        index = index->next; 
    }
}

// [helper function: get last element]
dll_intlist* last(dll_intlist* lst){
    while(lst != NULL){
        if(lst->next == NULL){
            return lst;
        }
        lst = lst->next;
    }
    return NULL;
}

// add two digits together 
dll_intlist* add_digits(dll_intlist* lst1, dll_intlist* lst2){
    dll_intlist* new_list;
    dll_intlist* last1 = last(lst1);
    dll_intlist* last2 = last(lst2);
    dll_intlist* temp_ptr;
    int temp_int = 0;

    // first iteration: set the last digit 
    if(last1->val+last2->val+temp_int >= 10){
        new_list = make_dll(last1->val+last2->val -10, NULL, NULL);
        temp_int = 1;
    } else {
        new_list = make_dll(last1->val+last2->val, NULL, NULL);
        temp_int = 0;
    }
    last1 = last1->prev;
    last2 = last2->prev;

    // body iterations: move from tail to front
    while(last1 != NULL && last2 != NULL){
        temp_ptr = new_list;
        if(last1->val+last2->val+temp_int >= 10){
            new_list->prev = make_dll(last1->val+last2->val+temp_int-10, NULL, temp_ptr);
            temp_int = 1;
            
        } else {
            new_list->prev = make_dll(last1->val+last2->val+temp_int, NULL, temp_ptr);
            temp_int = 0;
        }
        last1 = last1->prev;
        last2 = last2->prev;
        new_list = new_list->prev;
    }

    // final iteration: set the first digit
    if (temp_int == 1){
        new_list->prev = make_dll(1, NULL, new_list);
        new_list = new_list->prev;
    }

    return new_list;
}

