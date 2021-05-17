#include "board.h"
#include <stdlib.h>
#include <stdio.h>

// ask: malloc board_rep and make_pos

// [helper function: make a new board_rep]
board_rep make_rep(unsigned int width, unsigned int height, enum type type){
    // build board_rep union
    board_rep out;
    // if(out == NULL){
    //     fprintf(stderr, "make_rep: error mallocing board_rep union\n");
    //     exit(1);
    // }
    // build matrix or bits based on type
    switch (type)
    {
    case MATRIX:
        cell **matrix = (cell**)malloc(sizeof(cell*) * height);
        if(matrix == NULL){
            fprintf(stderr, "make_rep: error mallocing outer matirx\n");
            exit(1);
        }
        for(int i = 0; i < height; i++){
            matrix[i] = (cell*)malloc(sizeof(cell) * width);
            if(matrix[i] == NULL){
                fprintf(stderr, "make_rep: error mallocing inner matrix rows\n");
                exit(1);
            }
        }   
        out.matrix = matrix;
        break;
    case BITS:
        fprintf(stderr, "BITS type\n");
        exit(1);
        break;
    default:
        fprintf(stderr, "make_rep: type not bits or matirx\n");
        exit(1);
    }
}

board* board_new(unsigned int width, unsigned int height, enum type type){
    if(type == BITS){
        fprintf(stderr, "BITS type\n");
        exit(1);
    }

    board* out = (board*)malloc(sizeof(board));
    if(out == NULL){
        fprintf(stderr, "board_new: error mallocing\n");
        exit(1);
    }
    out->width = width;
    out->height = height;
    out->type = type;
    out->u = make_rep(width, height, type);
    return out;
}

void board_free(board* b){
    // free matrix
    cell **matrix = b->u.matrix;
    for(int i = 0; i < b->width; i++){
        free(matrix[i]);
    }
    free(matrix);
    free(b);
}

void board_show(board* b){
    // print header
    
}

cell board_get(board* b, pos p);

void board_set(board* b, pos p, cell c);

int main(){
    board* b = board_new(5,5,MATRIX);
    free(b);
}