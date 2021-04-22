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
    // declaring out_array
    *outlen = count_unique_elements(in, inlen)*2;
    int* out_arr = (int*)malloc(sizeof(int) * *outlen);
    if (out_arr == NULL) {
        fprintf(stderr, "error allocating out_arr \n");
        exit(1);
    }

    // loops through the in_array
    int j = 0;
    for (int i = 0; i < *outlen-1; i +=2) { 
        out_arr[i] = 1;
        while (in[j] == in[j+1]) {
            out_arr[i] ++;
            j ++;
        }
        out_arr[i+1] = in[j];
        j++;
        printf("%d %d, ", out_arr[i], out_arr[i+1]);
    }

    return out_arr;
}

void rle_decode(int* in, unsigned int inlen, int** out, unsigned int* outlen) {
    printf("in array %d \n", *out[0]);
    printf("in array %d \n", *out[1]);
    printf("in array %d \n", *out[2]);
    printf("in array %d \n", *out[3]);
    // *out = (int*)malloc(sizeof(int) * 8);
    unsigned int i, j = 0, count = 0;
    for (i = 0; i < inlen - 1; i += 2) {
        j = in[i];
        printf("j is %d \n", j);
        while(j > 0) {
            *out[count] = in[i+1];
            printf("%d ", *out[count]);
            j --;
            count ++;
        }
    }
    *outlen = count;

}

int main(){
    // original array
    int original_arr[] = {1,1,2,2,2,3,4,4};
    unsigned int original_len = 8;
    count_unique_elements(original_arr, original_len);

    // encode 
    unsigned int compressed_len;
    int* compressed_arr = rle_encode(original_arr, original_len, &compressed_len);
    printf("compressed len: %d \n", compressed_len);
    
    // decode 
    int* decoded_arr = (int[8]){};
    unsigned int decoded_len;
    rle_decode(compressed_arr, compressed_len, &decoded_arr, &decoded_len);

    // free
    free(compressed_arr);


}