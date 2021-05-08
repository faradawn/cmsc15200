#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>


// part 1: linked lists 

// [helper function: make a linked list]
intlist* make(int val, intlist* lst){
    intlist* new_ptr = (intlist*)malloc(sizeof(intlist*));
    if (new_ptr == NULL){
        fprintf(stderr, "error making new list");
        exit(1);
    }
    new_ptr->val = val;
    new_ptr->next = lst;
    return new_ptr;
}

// 1-1: prints the list to the screen
void show(intlist* lst) {
    if (lst == NULL) {
        printf("The list is empty");
    }
    intlist* index = lst;
    while(lst != NULL){
        // the last element  
        if (index->next == NULL){
            printf("%d", index->val);
            break;
        }
        // normal elements
        printf("%d -> ", index->val);
        index = index->next; 
    }
}

int main(){
    intlist* list1 = make(1, make(2, make(3, NULL)));
    show(list1);
}
