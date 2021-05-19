#include "pos.h"
#include <stdlib.h>
#include <stdio.h>

// 1-1 make a position quene struct
pos make_pos(unsigned int r, unsigned int c){
    pos out = {r, c};
    return out;
}

// [helper function: make one pq_entry element]
pq_entry* make_pq(pos p, pq_entry* next){
    pq_entry* out = (pq_entry*)malloc(sizeof(pq_entry));
    if(out == NULL){
        fprintf(stderr, "make_pq: error mallocing new\n");
        exit(1);
    }
    out->p = p;
    out->next = next;
    return out;
}

// [helper function: free one pq_entry element]
void free_pq(pq_entry* head){
    // free p struct and next pointer
    if(head){
        free_pq(head->next);
        free(head);
    }
}

// [helper function: show the pq linked list]
void show_pq(pq_entry* pq){
    if(pq){
        printf("(%u, %u) ", pq->p.r, pq->p.c);
        show_pq(pq->next);
    }
}

// 1-2 make a new posqueue of null
posqueue* posqueue_new(){
    posqueue *out = (posqueue*)malloc(sizeof(posqueue));
    if(out == NULL){
        fprintf(stderr, "posqueue_new: error mallocing new\n");
        exit(1);
    }
    out->head = NULL;
    out->tail = NULL;
    out->len = 0;
    return out;
}
// 1-3 add an element to the tail
void pos_enqueue(posqueue* q, pos p){
    if(q->tail == NULL){
        q->head = make_pq(p, NULL);
        q->tail = q->head;
    } else{
        q->tail->next = make_pq(p, NULL);
        q->tail = q->tail->next;
    }
    q->len = q->len + 1;
}

// 1-4 delete an element at the head
pos pos_dequeue(posqueue* q){
    if(q == NULL){
        fprintf(stderr, "pos_dequeue: queue is empty\n");
        exit(1);
    }
    pq_entry* cur = q->head;
    pos out = cur->p;
    q->head = q->head->next;
    q->len = q->len - 1;
    return out;
}

// 1-5 check if the given position is in the queue
bool posqueue_member(posqueue* q, pos p){
    pq_entry* lst = q->head;
    while(lst != NULL){
        if(lst->p.c == p.c && lst->p.r == p.r){
            return true;
        }
        lst = lst->next;
    }
    return false;
}

// 1-6 free the posqueue
void posqueue_free(posqueue* q){
    if(q == NULL)
        return;
    if(q->head)
        free_pq(q->head);
    // todo: why don't need free tail?
    free(q);
}
