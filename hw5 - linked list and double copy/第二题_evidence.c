#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>

void free_dll(dll_intlist* list){
    dll_intlist* next;
    while(list){
        next = list->next;
        free(list);
        list = next;
    }
    printf("dll list freed \n");
}


int main(){

    // part 2: double linked lists
    printf("\n\n === Part2: Double Linked Lists === \n");
    dll_intlist* num1 = make_dll(7, NULL, 
                        make_dll(8, NULL, 
                        make_dll(9, NULL, NULL)));
    num1->next->prev = num1;
    num1->next->next->prev = num1->next;
    dll_intlist* num2 = num1;
    printf("num1: 789\n");
    printf("num2: 789\n");
    printf("add_digit(num1, num2) \nanswer: ");
    dll_intlist* num_sum = add_digits(num1, num2);
    show_dll(num_sum);
    printf("\n\nThe End of HW5. Thank you!\n\n");
    free_dll(num1);

    return 0;
}
