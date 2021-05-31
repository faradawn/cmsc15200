#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char **argv){
    // check valid number of command-line argument
    printf("length %d\n", argc);
    if(argc != 9){
        fprintf(stderr, "wrong number of command-line arg\n");
        exit(1);
    }

    // read commandline input 
    unsigned int width, height, run, hangtime;
    for(int i=0; i<argc; i++){
        if(strcmp(argv[i], "-w") == 0)
            width = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-h") == 0)
            height = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-r") == 0)
            run = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-t") == 0)
            hangtime = atoi(argv[i+1]);
    }

    // create new game
    game* g = new_game(run, hangtime, width, height, MATRIX);

    printf("width: %u, height: %u, run: %u, hangtime: %u \n", width, height, run, hangtime);
    board_show(g->b);
    
    // game in progress
    do {
        printf(g->player == BLACKS_TURN ? "Black enter: " : "White enter: ");
        unsigned int r, c;
        scanf("%u%u*u", &r, &c);
        pos pos1 = make_pos(r,c);
        printf("pos entered: %u, %u\n", pos1.r, pos1.c);
        place_piece(g, pos1);
        printf("piece placed\n");
        board_show(g->b);
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



    // free game
    game_free(g);

}

// make play; ./play -w 8 -h 4 -r 3 -t 2
// make play; ./play -w 5 -h 3 -r 2 -t 3