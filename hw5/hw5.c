#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>


// part 1: linked lists 

// [helper function: make a linked list]
intlist* make(int val, intlist* lst){
    intlist* new_unit = (intlist*)malloc(sizeof(intlist*));
    if (new_unit == NULL){
        fprintf(stderr, "error making new list");
        exit(1);
    }
    new_unit->val = val;
    new_unit->next = lst;
    return new_unit;
}

// 1-1: prints the list to the screen
void show(intlist* lst) {
    if (lst == NULL) {
        printf("The list is empty"); // todo remove
    }
    intlist* index = lst;
    while(index != NULL){
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
// 1-2: get the nth element of a list 
int get_nth(intlist* lst, unsigned int n){
    if (lst == NULL) {
        printf("The list is empty");
    }
    intlist* index = lst;
    while(index != NULL){
        if(n == 0){
            return index->val;
        }
        index = index->next;
        n--;
    }
    fprintf(stderr, "get_nth: list not long enough\n");
    exit(1);
}

// 1-3: set the value of struct of the given index 
void set_nth(intlist* lst, unsigned int n, int new_val){
    if (lst == NULL) {
        printf("The list is empty");
    }
    intlist* index = lst;
    while(index != NULL){
        if(n == 0){
            index->val = new_val;
        }
        index = index->next;
        n--;
    }
    fprintf(stderr, "set_nth: list not long enough\n");
    exit(1);
}

// 1-4: insert an element after the choosen element
void insert_after(intlist* lst, int val, int new_val){
    if (lst == NULL) {
        printf("The list is empty");
    }
    intlist* index = lst;
    while(index != NULL){
        if(index->val == val){
            index->next = make(new_val, index->next);
            break;
        }
        index = index->next;
        if (index == NULL){
            fprintf(stderr, "insert_after: list doesn't contain target\n");
            exit(1);
        }
    }
}

// 1-5: insert an element before the element of the given val
intlist* insert_before(intlist* lst, int val, int new_val){
    if (lst == NULL) {
        printf("The list is empty");
    } else if (lst->val == val){
        // if the first element is the match
        return make(new_val, lst);
    }

    intlist* index = lst;
    while(index != NULL){
        printf("%d, \n", index->val);
        if(index->next->val == val){
            index->next = make(new_val, index->next);
            return lst;
        }
        index = index->next;
        if (index == NULL){
            fprintf(stderr, "insert_before: list doesn't contain target\n");
            exit(1);
        }
    }
    return lst;
}

// 1-6: deduplicate a give list 
intlist* no_duplicates(intlist* lst){
    if (lst == NULL) {
        printf("The list is empty");
    }
    intlist* index = lst;
    intlist* back_index = lst;
    while(index->next != NULL){
        printf("iter %d\n", index->val);
        while(back_index != index->next){
            if(index->next->val == back_index->val){
                index->next = index->next->next;
                printf("end inner while %d\n", index->val);
                break;
            } 
            back_index = back_index->next;
            // might able to sumplify 
            if(back_index == index->next){
                index = index->next;
                break;
            }
        }        
        back_index = lst;
    }
    return lst;
}


// part2: large numbers 

// [helper function: make double linked list]
dll_intlist* make_dll(int val, dll_intlist* prev, dll_intlist* next){
    dll_intlist* new_unit = (dll_intlist*)malloc(sizeof(dll_intlist*));
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
        if (index->next == NULL){
            printf("%d", index->val);
            break;
        }
        printf("%d -> ", index->val);
        index = index->next; 
    }
}

// add two digits together 
dll_intlist* add_digits(dll_intlist* lst1, dll_intlist* lst2){
    
}


int main(){
    dll_intlist *a1, *a2, *a3;
    a1->val = 1;
    a1->prev = NULL;
    a1->next = a2;
    a2->val = 9;
    a2->prev = a1;
    a2->next = NULL;
    show_dll(a1);

    // dll_intlist* a1 = {1, NULL, NULL};
    // dll_intlist* a2 = {9, a1, NULL};
    // dll_intlist* a3 = {3, a2, NULL};
    // a1->next = a2;
    // a2->next = a3;
    // show_dll(a1);
    
}
