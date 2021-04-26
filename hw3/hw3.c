#include "hw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// compresses the given array of positive integers
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen) {
    // count number of unique elements in the array
    unsigned int i = 0, j = 0, count = 1;
    while(i < inlen-1){
        if (in[i] != in[i+1]) {
            count ++;
        }
        i ++;
    }
    *outlen = count*2;
    
    // declaring out_array
    int* out_arr = (int*)malloc(sizeof(int) * *outlen);
    if (out_arr == NULL) {
        fprintf(stderr, "error allocating out_arr \n");
        exit(1);
    }

    // set values for out_arr
    for (i = 0; i < *outlen-1; i +=2) { 
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
        if (in[i] == 0){
            fprintf(stderr, "error: zero or negative count appeared");
        }
        j = in[i];
        while(j-- > 0) {
            out[count++] = &in[i+1];
        }
    }
    *outlen = count;
}

// [helper function] returns a substring given starting position and length
char* substring(char* in, int pos, unsigned int len) {
    unsigned int i = 0;
    char *out = (char*)malloc(sizeof(char) * (len+1));
    while (i < len) {
        out[i] = in[pos+i];
        i ++;
    }
    out[len] = '\0';
    return out;
}

// finds the matches within a string
char** find_matches(char* str, char* pat, unsigned int* nmatches) {
    unsigned int pat_len = strlen(pat);
    unsigned int i, k = 0, count = 0;
    
    // count the number of matches
    for (i = 0; i < strlen(str)-pat_len; i++) {
        while (str[k+i]==pat[k] || pat[k]=='?') {
            if (k == pat_len-1) {
                count ++;
                break;
            }
            k++;
        }
        k = 0;
    }
    printf("number of matches:\n %u \n", count);
    *nmatches = count;

    // allocate memory for the output array (array of pointers)
    char** out = (char**)malloc(sizeof(char*) * count); 
    if (out == NULL) {
        fprintf(stderr, "error allocating out_arr step 1 \n");
        exit(1);
    }
    for (i = 0; i < pat_len; i++) {
        *(out + i)  = (char*)malloc(sizeof(char) * (pat_len + 1));
        if (out[i] == NULL) {
            fprintf(stderr, "error allocating out_arr step 2\n");
            exit(1);
        }
    }

    // set values for the output array 
    // how to combine with count number ?
    unsigned int j = 0;
    for (i = 0; i < strlen(str)-pat_len; i++) {
        while (str[k+i]==pat[k] || pat[k]=='?') {
            if (k == pat_len-1) {
                out[j] = substring(str, i, pat_len);
                j ++;
                break;
            }
            k++;
        }
        k = 0;
    }
    return out;
}


char* concat_strings(char** strings, unsigned int num_strings) {
    unsigned int i, j, count = 0;
    // count the total length of the out put string 
    for (i = 0; i < num_strings; i ++) {
        count += strlen(strings[i]) + 1;
    }

    // allocate the output string 
    char* out = (char*)malloc(sizeof(char) * count);
    if (out == NULL) {
        fprintf(stderr, "error allocating new string");
    }

    // set values for the output array
    i = 0;
    unsigned int k = 0;
    for (i = 0; i < num_strings; i++) {
        for (j = 0; j < strlen(strings[i]); j++){
            out[k] = strings[i][j];
            k++;
        }
        out[k] = ' ';
        k++;
    }

    out[k-1] = '\0';
    return out;
}   