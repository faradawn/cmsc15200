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
    printf("count is %d \n", count);
    return count;
}

// compresses the given array of positive integers
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen) {
    // declare without malloc ?
    // does malloc initializes to zeros ?
    *outlen = count_unique_elements(in, inlen)*2;
    int* out_arr = (int*)malloc(sizeof(int) * *outlen);
    if (out_arr == NULL) {
        fprintf(stderr, "error allocating out_arr \n");
        exit(1);
    }

    int j = 0;
    
    for (int i = 0; i < *outlen-1; i +=2) { 
        out_arr[i] = 1;
        while (in[j] == in[j+1]) {
            out_arr[i] ++;
            j ++;
        }
        out_arr[i+1] = in[j];
        j++;
        printf("num %d: %d %d; \n", i, out_arr[i], out_arr[i+1]);
    }
    return out_arr;

}

int main(){
    int arr[] = {1,1,2,2,2,3,4,4};
    unsigned int arr_len = 8;
    count_unique_elements(arr, arr_len);
    unsigned int len;
    int* result_arr = rle_encode(arr, arr_len, &len);
    free(result_arr);
}