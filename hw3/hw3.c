#include "hw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// decodes the given array
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

// finds the matches within a string
char** find_matches(char* str, char* pat, unsigned int* nmatches) {
    unsigned int pat_len = strlen(pat);
    unsigned int i, j = 0, k = 0;
    char** out = (char*)malloc(sizeof(char) * 3); // change array size 
    for (i = 0; i < strlen(str)-pat_len; i++) {
        while (str[k+i]==pat[k++] || str[j++]=='?' && k<pat_len) {
            if (k == pat_len-1) {
                *out[j++] = ...; // write substring method 
            }
        }
    }
}

char* concat_strings(char** strings, unsigned int num_strings) {

}