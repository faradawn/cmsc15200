#include "logic.h"
#include <stdlib.h>
#include <stdio.h>

// create a new game struct
game* new_game(unsigned int run, unsigned int hangtime, unsigned int width,
               unsigned int height, enum type type){
                   // check if run is practical
                   if((height > width && run > height) ||
                    (width >= height && run > width)){
                       fprintf(stderr, "run too long\n");
                       exit(1);
                   }
                   game* out = (game*)malloc(sizeof(game));
                   out->run = run;
                   out->hangtime = hangtime;
                   if(type == MATRIX){
                       out->b = board_new(width, height, type);
                   } else {
                       fprintf(stderr, "new_game: BITS error\n");
                       exit(1);
                   }
                   out->player = BLACKS_TURN;
                   out->hanging = posqueue_new();
                   return out;
               }

// free the game struct [todo: check free other]
void game_free(game* g){
    board_free(g->b);
    posqueue_free(g->hanging);
    free(g);
    printf("game freed\n");
}

bool place_piece(game* g, pos p){
    // ilegal move
    

    // switch player

}

outcome game_outcome(game* g);
