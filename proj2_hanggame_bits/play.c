#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

unsigned int toInteger(char ch){
    int c = (int)ch;
    if(c>=48 && c<=57){
        return c-48;
    } else if(c>=65 && c<=90){
        return c-55;
    } else if(c>=97 && c<=122){
        return c-87;
    } else{
        return 404;
    }
}

int main(int argc, char **argv){
    // check valid number of command-line argument
    if(argc < 10){
        fprintf(stderr, "wrong number of command-line arguments\n");
        exit(1);
    }

    // read commandline input 
    unsigned int width, height, run, hangtime;
    enum type ty;
    for(int i=0; i<argc; i++){
        if(strcmp(argv[i], "-w") == 0)
            width = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-h") == 0)
            height = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-r") == 0)
            run = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-t") == 0)
            hangtime = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-b") == 0)
            ty = BITS;
        else if(strcmp(argv[i], "-m") == 0)
            ty = MATRIX;
    }

    // create new game
    game* g = new_game(run, hangtime, width, height, ty);
    board* b = g->b;
    printf("\n=== Game Created ===\n\n");
    board_show(b);
    int round = 1;
    
    // game in progress
    do {
        printf("\n=== Round %d ===\n", round);
        printf(g->player == BLACKS_TURN ? "Black enter: " : "White enter: ");
        char row, col;
        scanf("%c%c%*c", &row, &col); 
        pos p = make_pos(toInteger(row),toInteger(col));

        while(p.r>b->height-1 || p.r<0 || p.c<0 || p.c>b->width-1
        || board_get(b, p) != EMPTY ){
            printf("invalid pos, re-enter: ");
            scanf("%c%c%*c", &row, &col);
            p = make_pos(toInteger(row),toInteger(col));
        }

        place_piece(g, p);
        printf("\n");
        board_show(g->b);
        round ++;
    } while (game_outcome(g) == IN_PROGRESS);

    // display game outcome
    switch (game_outcome(g))
    {
    case BLACK_WIN:
        printf("Black Win!\n\n");
        break;
    case WHITE_WIN:
        printf("White Win!\n\n");
        break;
    case DRAW:
        printf("Draw!\n\n");
    default:
        printf("In Progress!\n\n");
        break;
    }

    game_free(g);
}

// make play; ./play -w 8 -h 4 -r 3 -t 2 -b