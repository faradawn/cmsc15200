#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>

void free_list(intlist* list){
    intlist* next;
    while(list){
        next = list->next;
        free(list);
        list = next;
    }
    printf("list freed \n");
}
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
    // part 1: linked lists
    printf("\n=== Part1: Linked Lists === \n");
    intlist* list1 = make(10, (make(20, make(30, NULL))));
    printf("show: ");
    show(list1);
    // get and set
    printf("\nget 0th element: %d", get_nth(list1, 0));
    printf("\nget 1st element: %d", get_nth(list1, 1));
    printf("\nget 2nd element: %d", get_nth(list1, 2));
    printf("\nset 2nd element to 40");
    set_nth(list1, 2, 40);
    printf("\nshow: ");
    show(list1);
    // insert after
    printf("\n\ninsert 30 after 20: ");
    insert_after(list1, 20, 30);
    printf("\nshow: ");
    show(list1);
    // insert before
    printf("\ninsert 25 before 30: ");
    printf("\nshow: ");
    show(insert_before(list1, 30, 25));
    // free
    free_list(list1);


    // part 2: double linked lists
    printf("\n\n === Part2: Double Linked Lists === \n");
    dll_intlist* num1 = make_dll(9, NULL, 
                        make_dll(8, NULL, 
                        make_dll(7, NULL, NULL)));
    num1->next->prev = num1;
    num1->next->next->prev = num1->next;
    dll_intlist* num2 = make_dll(9, NULL,
                        make_dll(9, NULL, NULL));
    num2->next->prev = num2;
    printf("num1: 987\n");
    printf("num2: 99\n");
    printf("add_digit(num1, num2) \nanswer: ");
    dll_intlist* num_sum = add_digits(num1, num2);
    show_dll(num_sum);
    printf("\n\nThe End of HW5. Thank you!\n\n");
    free_dll(num1);

    return 0;
}