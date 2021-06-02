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
                   // create a game
                   game* out = (game*)malloc(sizeof(game));
                   if(out == NULL){
                       fprintf(stderr, "new_game: malloc game out\n");
                       exit(1);
                   }

                   out->b = board_new(width, height, type);
                   out->hanging = posqueue_new();
                   out->run = run;
                   out->hangtime = hangtime;
                   out->player = BLACKS_TURN;

                   return out;
               }

// free the game struct 
void game_free(game* g){
    board_free(g->b); 
    posqueue_free(g->hanging); 
    free(g);
    printf("game freed\n");
}

// place a piece in the game
bool place_piece(game* g, pos p){
    // check if move is ilegal
    board* b = g->b;
    if(board_get(b, p) != EMPTY){
        printf("already a piece in the cell!\n");
        return false;
    } else if( p.r >= b->height || p.c >= b->width){
        printf("position out of bound\n");
        return false;
    }
    
    // place the piece and switch turns
    turn cur_turn = g->player;
    cell cur_color = BLACK;
    cell next_color = WHITE;
    if(cur_turn == BLACKS_TURN){
        board_set(b, p, BLACK); 
        g->player = WHITES_TURN;
    }
    else{
        cur_color = WHITE;
        next_color = BLACK;
        board_set(b, p, WHITE);   
        g->player = BLACKS_TURN;
    }
    
    // if hangtime doesn't runs out, don't dequeue
    posqueue* q = g->hanging;
    if(q->len < g->hangtime){
        pos_enqueue(q, p);
        return true;
    } 

    // prepare to deploy the dequeued piece   
    pos de_pos = pos_dequeue(q);
    board_set(b, de_pos, EMPTY);

    // descend the to-be-deplyed de_pos level by level
    if(de_pos.r < b->height){
        while(board_get(b, make_pos(de_pos.r+1, de_pos.c)) == EMPTY){
            // descend the above pieces down
            if(de_pos.r >= 1){
                pos above_pos = make_pos(de_pos.r-1, de_pos.c);
                while(above_pos.r >= 0 && board_get(b, above_pos)!= EMPTY && 
                !posqueue_member(q, above_pos)){
                    board_set(b, de_pos, board_get(b, above_pos));
                    board_set(b, above_pos, EMPTY);
                    above_pos = make_pos(above_pos.r-1, above_pos.c);
                }
            }
            // stop condition for descend 
            de_pos = make_pos(de_pos.r+1, de_pos.c);
            if(de_pos.r+1 >= b->height)
                break;
        }
    }

    // determine the color of the de_pos piece 
    cell color = (g->hangtime % 2 == 0) ? cur_color : next_color;
    board_set(b, de_pos, color);

    // enqueue the new piece     
    pos_enqueue(q, p);

    return true;    
}

// [helper function: count the number of runs in the four directions]
int num_run(board* b, cell color, direction dir, 
unsigned int r, unsigned int c){
    if(color == EMPTY)
        return 0;
    
    if(dir == RIGHT){
        if(r <= b->height-1 && c < b->width-1 && 
        board_get(b, make_pos(r, c+1)) == color){
            return 1 + num_run(b, color, RIGHT, r, c+1);
        } else{
            return 0;
        }
    }else if(dir == DOWN){
        if(r < b->height-1 && c <= b->width-1 && 
        board_get(b, make_pos(r+1, c)) == color){
            return 1 + num_run(b, color, DOWN, r+1, c);
        } else{
            return 0;
        }
    }else if(dir == UP_RIGHT){
        if(r > 0 && c < b->width-1 && 
        board_get(b, make_pos(r-1, c+1)) == color){
            return 1 + num_run(b, color, UP_RIGHT, r-1, c+1);
        } else{
            return 0;
        }
    }else{
        if(r < b->height-1 && c < b->width-1 && 
        board_get(b, make_pos(r+1, c+1)) == color){
            return 1 + num_run(b, color, UP_RIGHT, r+1, c+1);
        } else{
            return 0;
        }
    }
   
}

outcome game_outcome(game* g){
    if(g->b->type == BITS){
        return IN_PROGRESS;
    }
    int black_win = 0;
    int white_win = 0;
    cell** mat = g->b->u.matrix;

    // loop through every cell and count the runs
    for(int i=0; i<g->b->height; i++){
        for(int j=0; j<g->b->width; j++){
            if(num_run(g->b, mat[i][j], RIGHT, i, j) >= g->run-1 || 
            num_run(g->b, mat[i][j], DOWN, i, j) >= g->run-1 || 
            num_run(g->b, mat[i][j], UP_RIGHT, i, j) >= g->run-1 ||
            num_run(g->b, mat[i][j], DOWN_RIGHT, i, j) >= g->run-1 ){
                if(mat[i][j] == BLACK)
                    black_win ++;
                else 
                    white_win ++;
            }
        }
    }

    // output winning outcome 
    if(black_win > 0 && white_win > 0){
        return DRAW;
    } else if(black_win > 0 && white_win == 0){
        return BLACK_WIN;
    } else if(white_win> 0 && black_win == 0){
        return WHITE_WIN;
    } else {
        return IN_PROGRESS;
    }

}
