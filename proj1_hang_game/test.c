#include "board.h"
#include <stdlib.h>
#include <stdio.h>

// try enumboard_rep 

board_rep make_rep(unsigned int width, unsigned int height, enum type type){
    board_rep out;
    
    // build matrix or bits based on type
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
        out.matrix = matrix;
        out.bits = NULL;
        
    }
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
int main(){
    board_rep rep = make_rep(5,5,MATRIX);
    
    
}