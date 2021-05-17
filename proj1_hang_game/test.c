#include <stdlib.h>
#include <stdio.h>

// try enum

int** make_arr(){
    int **out = (int**)malloc(sizeof(int*) * 5);
    for(int i = 0; i < 5; i++){
        out[i] = (int*)malloc(sizeof(int) * 5);
    }
    printf("created\n");
    return out;
}

void free_arr(int** arr){
    for(int i =0; i<5; i++){
        free(arr[i]);
    }
    free(arr);
    printf("freed\n");
}

int main(){
    int** arr = make_arr();
    free_arr(arr);
}