#include "pos.h"
#include <stdlib.h>
#include <stdio.h>

// 1-1 make a position quene struct
pos make_pos(unsigned int r, unsigned int c){
    pos out = {r, c};
    return out;
}

// [helper function: make one pq_entry element]
pq_entry* make_entry(pos p){
    pq_entry* out = (pq_entry*)malloc(sizeof(pq_entry));
    out->p = p;
    out->next = NULL;
}

// [helper function: free one pq_entry element]
void free_entry(pq_entry* entry){
    // free p struct and next pointer
    free(entry->next);
    free(entry);
}

// 1-2 make a new posqueue of null
posqueue* posqueue_new(){
    posqueue *out = (posqueue*)malloc(sizeof(posqueue));
    out->head = NULL;
    out->tail = NULL;
    out->len = 0;
    return out;
}
// 1-3 add an element to the tail
void pos_enqueue(posqueue* q, pos p){
    q->tail->next = make_entry(p);
}

// 1-4 delete an element at the head
pos pos_dequeue(posqueue* q){
    if(q == NULL){
        fprintf(stderr, "pos_dequeue: queue is empty");
        exit(1);
    }
    pq_entry* cur = q->head;
    pos out = cur->p;
    q->head = q->head->next;
    free_entry(cur);
    return out;
}

bool posqueue_member(posqueue* q, pos p);

void posqueue_free(posqueue* q){
    if(q){
        free_entry(q->head);
        q->head = q->head->next;
        posqueue_free(q);
    }
}