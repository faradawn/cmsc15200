
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

// error segmentation! malloc sizeof (intlist*)

// stack allocated array can't shrink.
// heap allocated might ... with realloc 
    // [1,2,3] ... , yes
    // [1,2,3] [4], need copy to other place



// Part1: Key Functions
intlist* make_list(int val, intlist* lst){
    intlist* new_list = (intlist*)malloc(sizeof(intlist));
    if (new_list == NULL){
        fprintf(stderr, "error new list");
        exit(1);
    }
    new_list->val = val;
    new_list->next = lst;
    return new_list;
}

void free_list(intlist* list){
    // free linked list
    intlist* next;
    while(list){
        next = list->next;
        free(list);
        list = next;
    }
    printf("list freed \n");
}

void show_list(intlist* lst){
    while(lst){
        printf("%d ", lst->val);
        lst = lst->next;
    }
    printf("\n");
}

int sum_list(intlist* lst){
    if (lst == NULL){
        return 0;
    }
    return lst->val + sum_list(lst->next);
}



// todo: 1-D and 2-D array free


// Part2: High level functions
intlist* remove_front(intlist* lst){
    intlist* temp = lst;
    free(lst);
    return temp->next;
}


void update_front(intlist** lst){
    // update_front(&list1)
    intlist* temp = *lst;
    *lst = temp->next;
    // *lst = *lst->next;
    free(temp);    
}


intlist* find_evens(intlist* lst){
    intlist* curr = lst;
    intlist* head = NULL;
    intlist* tail;
    while(curr){
        if(curr->val % 2 == 0) {
            intlist* item = make_list(curr->val, NULL);
            if(head == NULL){
                head = item;
            } else {
                tail->next = item;
            }
            tail = item;
        }
        curr = curr->next;
    }
    return head;
}

