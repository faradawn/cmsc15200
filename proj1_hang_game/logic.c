#include "logic.h"
#include <stdlib.h>
#include <stdio.h>

// todo: check free function

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
    // if(g->b)
    //     board_free(g->b);
    // if(g->hanging)
    //     posqueue_free(g->hanging);
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
            de_pos = make_pos(de_pos.r+1, de_pos.c);
            if(de_pos.r+1 >= b->height)
                break;
        }
    }

    // after descend, place de_pos on board
    cell color = (g->hangtime % 2 == 0) ? cur_color : next_color;
    printf("cell color: %d\n", color);
    board_set(b, de_pos, color);

    // enqueue the new piece     
    pos_enqueue(q, p);
    printf("enqueued \n");

    return true;
    

    // switch player

}

outcome game_outcome(game* g);

int main(){
    printf(">> create new game:\n");
    game* g = new_game(3,2,8,4,MATRIX);
    board_show(g->b);

    printf("\n>> 1: place Black at (1.1): ");
    printf(place_piece(g, make_pos(1,1)) ? "true\n" : "false\n");
    board_show(g->b);
    show_pq(g->hanging->head);  

    printf("\n>> place White at (1.1): ");
    place_piece(g, make_pos(1,1));
    board_show(g->b);

    printf("\n\n>> 2: place White at (0.3): ");
    printf(place_piece(g, make_pos(0,3)) ? "true\n" : "false\n" );
    board_show(g->b);
    show_pq(g->hanging->head);

    printf("\n\n>> 3: place Black at (2.3): ");
    printf(place_piece(g, make_pos(2,3)) ? "true\n" : "false\n" );
    board_show(g->b);
    show_pq(g->hanging->head);

    printf("\n\n>> 4: place White at (1.2): ");
    printf(place_piece(g, make_pos(1,2)) ? "true\n" : "false\n" );
    board_show(g->b);
    show_pq(g->hanging->head);

    printf("\n\n>> 5: place Black at (0.2): ");
    printf(place_piece(g, make_pos(0,2)) ? "true\n" : "false\n" );
    board_show(g->b);
    show_pq(g->hanging->head);

    printf("\n\n>> 6: place White at (1.4): ");
    printf(place_piece(g, make_pos(1,4)) ? "true\n" : "false\n" );
    board_show(g->b);
    show_pq(g->hanging->head);
    

    printf(">> free game:\n");
    game_free(g);
    printf("game freed\n");
}

// leaks --atExit -- ./leak