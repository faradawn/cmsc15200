#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

intlist* find_even(intlist* lst){
    intlist* mover;
    intlist* index = lst;
    lst = NULL;
    while(index){
        if(index->val %2 == 0){
            intlist* item = make_list(index->val, NULL);
            if(lst == NULL){
                lst = item;
            } else {
                mover->next = item;
            }
            mover = item;
        }
        index = index->next;
    }
    return lst;    
    
}

int main(){
    intlist* list1 = make_list(1, make_list(2, make_list(3, make_list(4,NULL))));
    show(list1);
    intlist* res1 = find_even(list1);
    show(res1);
    free_list(res1);

}