#include "hw3.h"
#include <stdio.h>
#include <stdlib.h>

// counts the number of unique elements in an array
int count_unique_elements(int in[], unsigned int inlen) {
    int count = 1;
    for (int i = 0; i < inlen - 1; i++) {
        if (in[i] != in[i+1]) {
            count ++;
        }
    }
    return count;
}

// compresses the given array of positive integers
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen) {
    // declaring out_array
    *outlen = count_unique_elements(in, inlen)*2;
    int* out_arr = (int*)malloc(sizeof(int) * *outlen);
    if (out_arr == NULL) {
        fprintf(stderr, "error allocating out_arr \n");
        exit(1);
    }

    // set values for out_arr
    int j = 0;
    for (int i = 0; i < *outlen-1; i +=2) { 
        out_arr[i] = 1;
        while (in[j] == in[j+1]) {
            out_arr[i] ++;
            j ++;
        }
        out_arr[i+1] = in[j];
        j++;
    }

    return out_arr;
}

void rle_decode(int* in, unsigned int inlen, int** out, unsigned int* outlen) {
    unsigned int i, j = 0, count = 0;
    for (i = 0; i < inlen - 1; i += 2) {
        j = in[i];
        while(j-- > 0) {
            out[count++] = &in[i+1];
        }
    }
    *outlen = count;
}
