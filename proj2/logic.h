#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>
#include "board.h"


enum turn {
    BLACKS_TURN,
    WHITES_TURN
};

typedef enum turn turn;


enum outcome {
    IN_PROGRESS,
    BLACK_WIN,
    WHITE_WIN, 
    DRAW
};

typedef enum outcome outcome;


struct game {
    unsigned int run, hangtime;
    board* b;
    posqueue* hanging;
    turn player;
};

typedef struct game game;

// create a new game
game* new_game(unsigned int run, unsigned int hangtime, unsigned int width,
               unsigned int height, enum type type);

// free the game
void game_free(game* g);

// place a piece of the board and return if success
bool place_piece(game* g, pos p);

// report the outcome of the game
outcome game_outcome(game* g);

// to check runs in the 4 directions
enum direction{
    RIGHT,
    DOWN,
    UP_RIGHT,
    DOWN_RIGHT,
};
typedef enum direction direction;

// check count number of runs in every direction 
int num_run(board* b, cell color, direction dir, 
unsigned int r, unsigned int c);

// [helper function: convert char input to unsigned int]
unsigned int toInteger(char c);

// [helper function: check if the board is full]
bool check_full(board* b);

#endif /* LOGIC_H */
