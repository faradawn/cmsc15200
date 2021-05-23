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
    free(g);
}

bool pos_compare(pos a, pos b){
    if(a.c == b.c && a.r == b.r)
        return true;
    else 
        return false;
}


// place a piece in the game
bool place_piece(game* g, pos p){
    // check if move is ilegal
    board* b = g->b;
    if(board_get(b, p) != EMPTY){
        printf("already a piece in the cell. ");
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
    printf(" deququed (%d, %d) \n", de_pos.r, de_pos.c);
    board_set(b, de_pos, EMPTY);

    // descend the to-be-deplyed de_pos level by level
    if(de_pos.r < b->height){
        while(board_get(b, make_pos(de_pos.r+1, de_pos.c)) == EMPTY){
            printf(" while first (%d, %d) \n", de_pos.r, de_pos.c);
            // descend the above pieces down
            if(de_pos.r >= 1){
                pos above_pos = make_pos(de_pos.r-1, de_pos.c);
                printf(" above is (%d, %d) \n", above_pos.r, above_pos.c);
                while(above_pos.r >= 0 && board_get(b, above_pos)!= EMPTY && 
                !posqueue_member(q, above_pos)){
                    board_set(b, de_pos, board_get(b, above_pos));
                    board_set(b, above_pos, EMPTY);
                    above_pos = make_pos(above_pos.r-1, above_pos.c);
                    printf("inner while\n");
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
    printf("cell color: %d\n", color);
    board_set(b, de_pos, color);

    // enqueue the new piece     
    pos_enqueue(q, p);
    printf("enqueued \n");

    return true;    
}

// [helper function: count the number of runs in the four directions]
int num_run(board* b, cell color, direction dir, 
unsigned int r, unsigned int c){
    if(color == EMPTY)
        return 0;
    
    if(dir == RIGHT){
        printf("checking right (%d, %d), ", r, c+1);
        if(r <= b->height-1 && c < b->width-1 && 
        board_get(b, make_pos(r, c+1)) == color){
            return 1 + num_run(b, color, RIGHT, r, c+1);
        } else{
            return 0;
        }
    }else if(dir == DOWN){
        printf("checking down (%d, %d), ", r+1, c);
        if(r < b->height-1 && c <= b->width-1 && 
        board_get(b, make_pos(r+1, c)) == color){
            return 1 + num_run(b, color, DOWN, r+1, c);
        } else{
            return 0;
        }
    }else if(dir == UP_RIGHT){
        printf("checking upright (%d, %d), ", r-1, c+1);
        if(r > 0 && c < b->width-1 && 
        board_get(b, make_pos(r-1, c+1)) == color){
            return 1 + num_run(b, color, UP_RIGHT, r-1, c+1);
        } else{
            return 0;
        }
    }else{
        printf("checking upright (%d, %d), ", r+1, c+1);
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
        fprintf(stderr, "BITS\n");
        exit(1);
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


// int main(){
//     printf(">> create new game:\n");
//     game* g = new_game(3,2,8,4,MATRIX);
//     board_show(g->b);

//     printf("\n>> 1: place Black at (1.1): ");
//     printf(place_piece(g, make_pos(1,1)) ? "true\n" : "false\n");
//     board_show(g->b);
//     show_pq(g->hanging->head);  

//     printf("\n>> place White at (1.1): ");
//     place_piece(g, make_pos(1,1));
//     board_show(g->b);

//     printf("\n\n>> 2: place White at (0.3): ");
//     printf(place_piece(g, make_pos(0,3)) ? "true\n" : "false\n" );
//     board_show(g->b);
//     show_pq(g->hanging->head);

//     printf("\n\n>> 3: place Black at (2.3): ");
//     printf(place_piece(g, make_pos(2,3)) ? "true\n" : "false\n" );
//     board_show(g->b);
//     show_pq(g->hanging->head);

//     printf("\n\n>> 4: place White at (1.2): ");
//     printf(place_piece(g, make_pos(1,2)) ? "true\n" : "false\n" );
//     board_show(g->b);
//     show_pq(g->hanging->head);

//     printf("\n\n>> 5: place Black at (0.2): ");
//     printf(place_piece(g, make_pos(0,2)) ? "true\n" : "false\n" );
//     board_show(g->b);
//     show_pq(g->hanging->head);

//     printf("\n\n>> 6: place White at (1.4): ");
//     printf(place_piece(g, make_pos(1,4)) ? "true\n" : "false\n" );
//     board_show(g->b);
//     show_pq(g->hanging->head);

//     switch (game_outcome(g))
//     {
//     case BLACK_WIN:
//         printf("Black Win!\n");
//         break;
//     case WHITE_WIN:
//         printf("White Win!\n");
//         break;
//     case DRAW:
//         printf("Draw!\n");
//     default:
//         printf("In Progress!\n");
//         break;
//     }
    

//     printf(">> free game:\n");
//     game_free(g);
//     printf("game freed\n");
// }

// // leaks --atExit -- ./leak