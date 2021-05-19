#include "logic.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    // Part1: Testing pos.c
    printf("=== Part1: Pos ===\n");
    printf(">> create new queue:\n");
    posqueue* q = posqueue_new();
    printf("empty queue create\n\n");
    printf(">> enqueue (1,1), (0,3), (2,3):\n");
    pos_enqueue(q, make_pos(1,1));
    pos_enqueue(q, make_pos(0,3));
    pos_enqueue(q, make_pos(2,3));
    show_pq(q->head);
    printf("\n\n>> dequeue (1,1):\n");
    pos_dequeue(q);
    show_pq(q->head);
    printf("\n\n>> free queue:\n");
    posqueue_free(q);
    printf("queue freed\n");


    // Part2: Testing board.c
    printf("\n=== Part2: Board ===\n");
    printf(">> create new board:\n\n");
    board* b = board_new(8,4,MATRIX);
    board_show(b);
    // place two pieces
    printf("\n>> place a BLACK piece on pos(1,1):\n");
    board_set(b, make_pos(1,1), BLACK);
    printf(">> place a WHITE piece on pos(0,3):\n");
    board_set(b, make_pos(0,3), WHITE);
    printf(">> get the piece on pos(1,1):\n");
    printf("%d ", board_get(b, make_pos(1,1)));
    printf("(1 is BLACK, 2 is WHITE)\n\n");
    board_show(b);
    // free board
    printf("\n>> free board:\n");
    free(b);
    printf("board freed\n");


    // Part3: Testing logic.c
    printf("\n=== Part3: Logic ===\n");
}