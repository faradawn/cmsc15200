#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* build_dynamic_array(){
    // initialize array with a length of 2
    unsigned int len = 2;
    int* out = (int*)malloc(sizeof(int)*len);
    out[0] = 0;
    out[1] = 1;
    // setting the 3rd element
    out[2] = 2; 

    return out;
}

int main () {
    int* arr1 = build_dynamic_array();

    printf("arr[0]: %d \n", arr1[0]);
    printf("arr[1]: %d \n", arr1[1]);
    printf("arr[2]: %d \n", arr1[2]);

    free(arr1);
}