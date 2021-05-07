// part 1: linked lists
typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

void show(intlist* lst);
int get_nth(intlist* lst, unsigned int n);
void set_nth(intlist* lst, unsigned int n, int new_val);
void insert_after(intlist* lst, int val, int new_val);
intlist* insert_before(intlist* lst, int val, int new_val);
intlist* no_duplicates(intlist* lst);

// part 2: big numbers
typedef struct dll_intlist dll_intlist;

struct dll_intlist {
    int val;
    dll_intlist* prev;
    dll_intlist* next;
};

dll_intlist* add_digits(dll_intlist* lst1, dll_intlist* lst2);
