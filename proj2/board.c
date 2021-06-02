#include "board.h"
#include <stdlib.h>
#include <stdio.h>

// [helper function: make a new board_rep]
board_rep make_rep(unsigned int width, unsigned int height, enum type type){
    board_rep out;
    // make MATRIX board
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
        // make empty
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++)
                matrix[i][j] = EMPTY;
        }
        out.matrix = matrix;
        
    } 

    // make BITS board 
    else { 
        int arr_len = width * height % 16 + 1;
        printf("bits array length: %d\n", arr_len);
        unsigned int* bits = (unsigned int*)(calloc(arr_len, sizeof(unsigned int)));
        if(bits == NULL){
            fprintf(stderr, "make_rep: error mallocing bits\n");
            exit(1);
        }
        out.bits = bits;
    }

    return out;
}

// build a new board
board* board_new(unsigned int width, unsigned int height, enum type type){
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
    if(b->type == MATRIX){
        for(int i = 0; i < b->height; i++){
            free(b->u.matrix[i]);
        }
        free(b->u.matrix);
        free(b);
        printf("matrix board freed\n");
    } else {
        free(b->u.bits);
        free(b);
        printf("bits board freed\n");
    }
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

    // print MATRIX board
    if(b->type == MATRIX){
        cell** matrix = b->u.matrix;
        for(i = 0; i < b->height; i++){
            print_index(i);
            printf(" ");
            for(j = 0; j < b->width; j++){
                switch (matrix[i][j]) {
                case BLACK:
                    printf("*");
                    break;
                case WHITE:
                    printf("o");
                    break;
                default:
                    printf(".");
                    break;
                }
            }
            printf("\n");
        }
    }

    // print BITS board
    else {
        int index = 0, count = 0;
        // copy one element in the bits array at a time
        unsigned int element = b->u.bits[index];
        // main loops
        for(i = 0; i<b->height; i++){
            print_index(i);
            printf(" ");
            for(j = 0; j<b->width; j++){
                if(element >> 2 & 0b01)
                    printf("*");
                else if(element >> 2 & 0b10)
                    printf("o");
                else
                    printf(".");
                count ++;
                // switch to next element when 16 cells are printed
                if(count >= 15){
                    index ++;
                    element = b->u.bits[index];
                    count = 0;
                }
            }
            printf("\n");
        }
    }
}

// get an element of the board
cell board_get(board* b, pos p){
    if(p.r>b->height-1 || p.r<0 || p.c<0 || p.c>b->width-1){
        fprintf(stderr, "board_get: position out: (%d, %d)\n", p.r, p.c);
        exit(1);
    }
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
    if(b->type == MATRIX){
        b->u.matrix[p.r][p.c] = c;
    } else {
        fprintf(stderr, "board_set: error BITS\n");
        exit(1);
    }
}

int main(){
    // Part2: Testing board.c
    printf("\n=== Part2: Board ===\n");
    printf(">> create new board:\n\n");
    board* b = board_new(9, 4, BITS);
    board_show(b);
    
    // place piece 

    // free board
    printf("\n>> free board:\n");
    board_free(b);

}