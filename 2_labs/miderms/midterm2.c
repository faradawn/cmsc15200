#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

int lists_equal(intlist* lst1, intlist* lst2){
    if(lst1 == NULL && lst2 == NULL){
        return 1;
    }
    int i = 0;
    while(lst1){
        if(lst1->val != lst2->val){
            return 0;
        }
        if(lst1->next == NULL && lst2->next != NULL ){
            return 0;
        } else if(lst1->next != NULL && lst2->next == NULL){
            return 0;
        }
        lst1 = lst1->next;
        lst2 = lst2->next;
    }
    return 1;
}


intlist* make_list(int val, intlist* lst){
    intlist* new_list = (intlist*)malloc(sizeof(intlist));
    if (new_list == NULL){
        fprintf(stderr, "error making list");
        exit(1);
    }
    new_list->val = val;
    new_list->next = lst;
    return new_list;
}

intlist* filter_by_list(intlist* input, intlist* filter){
    if (input == NULL || filter == NULL){
        return NULL;
    }
    intlist* out = NULL;
    intlist* out_head = out;
    intlist* input_head = input;

    while(filter){
        while(input){
            if(input->val == filter->val){
                if(out == NULL){ 
                    // first iteration
                    out = make_list(filter->val, NULL);
                    out_head = out;
                } else {
                    out->next = make_list(filter->val, NULL);
                }
                out = out->next;
                break;
            }
            input = input->next;
        }
        // set input back to head 
        input = input_head;
        // move filter forward one step 
        filter = filter->next;
    }

    return out_head;
}

// part 2

enum home_tag {HOUSE, APARTMENT};

struct house {
    unsigned int num_bedrooms;
    unsigned int num_bathrooms;
};

struct apartment {
    unsigned int num_bedrooms;
    unsigned int num_bathrooms;
    unsigned int floor_num;
    int elevator;
};


union home {
    struct house house;
    struct apartment apartment;
};

struct tagged_home {
    enum home_tag tag;
    union home home;
};

int in_suburbs(struct tagged_home* neighborhood, unsigned int num_homes) {
    if(num_homes == 0){
        return 0;
    }

    int count = 0;
    for (int i = 0; i < num_homes; i ++){
        if(neighborhood[i].tag == HOUSE){
            count ++;
        }
    }

    // if number of houses if more than half of total homes
    if(count * 2 > num_homes){
        return 1;
    } else{
        return 0;
    }
}

typedef struct apartment apart;

struct apartment* find_apartments(struct apartment* apartments, 
                                  unsigned int num_apartments,
                                  unsigned int min_bedrooms, 
                                  unsigned int min_bathrooms,
                                  unsigned int max_flights_of_stairs,
                                  unsigned int* num_acceptable_apartments){

    int i, count = 0;
    
    for(i = 0; i < num_apartments; i++){
        if(apartments[i].num_bathrooms>min_bathrooms && apartments[i].num_bedrooms>min_bedrooms){
            if(apartments[i].floor_num <= max_flights_of_stairs || apartments[i].elevator){
                count ++;
            }
        }
    }

    // update output parameter
    *num_acceptable_apartments = count;
    
    if (count != 0){
        // apart is the type of apartment struct
        apart* out = (apart*)malloc(sizeof(apart)*count);
        if (out == NULL){
             fprintf(stderr, "error allocing apartment array");
            exit(1);
        }

        int j = 0;
        for(i = 0; i < num_apartments; i++){
            if(apartments[i].num_bathrooms>min_bathrooms && apartments[i].num_bedrooms>min_bedrooms){
                if(apartments[i].floor_num <= max_flights_of_stairs || apartments[i].elevator){
                    out[j] = apartments[i];
                    j ++; 
                }
            }
        }

        return out;
    } else {
        // if no match, return NULL
        return NULL;
    }
}    



void free_list(intlist* list){
    intlist* next;
    while(list){
        next = list->next;
        free(list);
        list = next;
    }
    printf("list freed \n");
}

void show(intlist* lst){
    while(lst){
        printf("%d ", lst->val);
        lst = lst->next;
    }
    printf("\n");
}

int main(){
    intlist* list1 = make_list(1, make_list(1, make_list(2, make_list(3, make_list(4, NULL)))));
    intlist* list2 = make_list(1, make_list(3, make_list(5, make_list(8, NULL))));
    intlist* list3 = filter_by_list(list1, list2);
    show(list3);
    free_list(list3);
    


}