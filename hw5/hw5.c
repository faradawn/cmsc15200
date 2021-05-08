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
    
}



int main(){
    intlist* list1 = make(10, make(20, make(30, NULL)));
    intlist* list2 = insert_before(list1, 30, 100);
    show(list2);
}
