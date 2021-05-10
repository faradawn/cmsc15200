// part 1: linked lists
typedef struct intlist intlist;
struct intlist {
    int val;
    intlist* next;
};
// [helper function: make a linked list]
intlist* make(int val, intlist* lst);
// prints all the elements of a linked list 
void show(intlist* lst);
// get the nth element of a list 
int get_nth(intlist* lst, unsigned int n);
// set the value of the struct at the given index
void set_nth(intlist* lst, unsigned int n, int new_val);
// insert an element after the choosen element
void insert_after(intlist* lst, int val, int new_val);
// insert an element before the element of the given val
intlist* insert_before(intlist* lst, int val, int new_val);
// deduplicate a given list
intlist* no_duplicates(intlist* lst);


// part 2: big numbers
typedef struct dll_intlist dll_intlist;
struct dll_intlist {
    int val;
    dll_intlist* prev;
    dll_intlist* next;
};
// [helper function: make double linked list]
dll_intlist* make_dll(int val, dll_intlist* prev, dll_intlist* next);
// [helper function: show the double linked list]
void show_dll(dll_intlist* lst);
// [helper function: get last element]
dll_intlist* last(dll_intlist* lst);
// add two digits together
dll_intlist* add_digits(dll_intlist* lst1, dll_intlist* lst2);

