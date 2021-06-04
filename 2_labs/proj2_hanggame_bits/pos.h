#ifndef POS_H
#define POS_H

#include <stdbool.h> 

struct pos {
    unsigned int r, c;
};

typedef struct pos pos;


typedef struct pq_entry pq_entry;

struct pq_entry {
    pos p;
    pq_entry* next;
};


struct posqueue {
    pq_entry *head, *tail;
    unsigned int len;
};

typedef struct posqueue posqueue;

// [helper function: make one pq_entry element]
pq_entry* make_pq(pos p, pq_entry* next);

// [helper function: show the pq linked list]
void show_pq(pq_entry* pq);

// [helper function: free one pq_entry element]
void free_pq(pq_entry* head);

// 1-1 make a position quene struct
pos make_pos(unsigned int r, unsigned int c);

// 1-2 make a new posqueue of null
posqueue* posqueue_new();

// 1-3 add an element to the tail
void pos_enqueue(posqueue* q, pos p);

// 1-4 delete an element at the head
pos pos_dequeue(posqueue* q);

// 1-5 check if the given position is in the queue
bool posqueue_member(posqueue* q, pos p);

// 1-6 free the posqueue
void posqueue_free(posqueue* q);

#endif /* POS_H */
