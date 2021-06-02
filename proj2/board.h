#ifndef BOARD_H
#define BOARD_H
 
#include "pos.h"

enum cell {
    EMPTY,
    BLACK,
    WHITE
};

typedef enum cell cell;


union board_rep {
    enum cell** matrix;
    unsigned int* bits;
};

typedef union board_rep board_rep;

enum type {
    MATRIX, BITS
};

 
struct board {
    unsigned int width, height;
    enum type type;
    board_rep u;
};

typedef struct board board;

// [helper function: build a new board_rep]
board_rep make_rep(unsigned int width, unsigned int height, enum type type);

// build a new board
board* board_new(unsigned int width, unsigned int height, enum type type);

// free a given board
void board_free(board* b);

// display a given board
void board_show(board* b);

// get an element of the board
cell board_get(board* b, pos p);

// set an element of the board
void board_set(board* b, pos p, cell c);


// [helper function: set ith bit in a number 1]
unsigned int setOne(unsigned int num, unsigned int i);

// [helper function: set ith bit in a number 0]
unsigned int setZero(unsigned int num, unsigned int i);


#endif /* BOARD_H */
 