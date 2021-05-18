#include "logic.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    // Part1: Testing pos.c


    // Part2: Testing board.c
    // create a new board
    printf(">> create new board:\n");
    board* b = board_new(8,4,MATRIX);
    printf("new board created\n>> show board:\n");
    board_show(b);

    // place two pieces
    printf(">> place a BLACK piece on pos(1,1):\n");
    board_set(b, make_pos(1,1), BLACK);
    printf(">> place a WHITE piece on pos(0,3):\n");
    board_set(b, make_pos(0,3), WHITE);
    printf(">> get the piece on pos(1,1):\n");
    printf("%d ", board_get(b, make_pos(1,1)));
    printf("(1 is BLACK, 2 is WHITE)\n");
    printf(">> show board:\n");
    board_show(b);

    //todo: test pq at the end

    // free board
    printf(">> free board:\n");
    free(b);
    printf("board freed\n");


    // Part3: Testing logic.c
}