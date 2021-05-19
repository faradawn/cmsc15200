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

bool pos_compare(pos a, pos b){
    if(a.c == b.c && a.r == b.r)
        return true;
    else 
        return false;
}


// place a piece in the game
bool place_piece(game* g, pos p){
    board* b = g->b;
    // check ilegal move
    if(board_get(b, p) != EMPTY){
        printf("already a piece in the cell\n");
        return false;
    } else if( p.r >= b->height || p.c >= b->width){
        printf("position out of bound\n");
        return false;
    }
    
    // place piece and switch turns
    turn cur_turn = g->player;
    cell cur_color = BLACK;
    cell next_color = WHITE;
    if(cur_turn = BLACKS_TURN){
        board_set(b, p, BLACK); 
        g->player = WHITES_TURN;
    }
    else{
        cur_color = WHITE;
        next_color = BLACK;
        board_set(b, p, WHITE);   
        g->player = BLACKS_TURN;
    }

    // update board
    posqueue* q = g->hanging;
    // before hangtime runs out
    if(q->len <= g->hangtime){
        pos_enqueue(q, p);
        return true;
    } 

    pos de_pos = pos_dequeue(q);

    // the frist few moves before run runs out
    if(de_pos.r == -1){
        return true;
    }

    
    
    pos_enqueue(q, p);
    

    // switch player

}

outcome game_outcome(game* g);
