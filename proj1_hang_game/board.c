#include "board.h"
#include <stdlib.h>
#include <stdio.h>

// [helper function: make a new board_rep]
board_rep make_rep(unsigned int width, unsigned int height, enum type type){
    board_rep out;
    if(type == MATRIX){
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
        // make emptry
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++)
                matrix[i][j] = EMPTY;
        }
        out.matrix = matrix;
        
    } else {
        fprintf(stderr, "make_rep: error mallocing inner matrix rows\n");
        exit(1);
    }
    return out;
    

}
// build a new board
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

// free a given board
void board_free(board* b){
    // free matrix
    cell **matrix = b->u.matrix;
    for(int i = 0; i < b->width; i++){
        free(matrix[i]);
    }
    free(matrix);
    free(b);
}

// [healper funciton: print header or left bar of the board]
void print_index(int i){
    if(i < 0){
        printf(" ");
    } else if(i >= 0 && i < 9){
        printf("%d", i);
    } else if(i >= 10 && i < 36){
        printf("%c", 'A'+i-10);
    } else{
        printf("?");
    }
}
// display a given board
void board_show(board* b){
    // print header
    int i, j;
    for(i = 0; i < b->width + 2; i++){
        print_index(i-2);
    }
    printf("\n");

    // print board
    if(b->type == MATRIX){
        cell** matrix = b->u.matrix;
        for(i = 0; i < b->height; i++){
            print_index(i);
            printf(" ");
            for(j = 0; j < b->width; j++){
                switch (matrix[i][j])
                {
                case BLACK:
                    printf("*");
                    break;
                case WHITE:
                    printf("o");
                default:
                    printf(".");
                    break;
                }
            }
            printf("\n");
        }
    }
}

// get an element of the board
cell board_get(board* b, pos p){
    switch (b->type)
    {
    case MATRIX:
        return b->u.matrix[p.r][p.c];
    case BITS:
        fprintf(stderr, "board_get: error BITS\n");
        exit(1);
    default:
        break;
    }
}

// set an element of the board
void board_set(board* b, pos p, cell c){
    switch (b->type)
    {
    case MATRIX:
        b->u.matrix[p.r][p.c] = c;
    case BITS:
        fprintf(stderr, "board_set: error BITS\n");
        exit(1);
    default:
        break;
    }
}


int main(){
    board* b = board_new(5,5,MATRIX);
    board_show(b);
    free(b);
}