typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

// make int list with malloc
intlist* make_list(int val, intlist* lst);

// free int list 
void free_list(intlist* list);

// show int list 
void show(intlist* lst);