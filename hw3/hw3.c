#include "hw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [helper function] counts the number of unique elements in an array
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
    printf("number of matches: %u \n", count);
    *nmatches = count;

    // allocate memory for the array
    char** out = (char**)malloc(sizeof(char*) * count); 
    if (out == NULL) {
        fprintf(stderr, "error allocating out_arr \n");
        exit(1);
    }
    for (i = 0; i < pat_len; i++) {
        *(out + i)  = (char*)malloc(sizeof(char) * (pat_len + 1));
        if (out[i] == NULL) {
            fprintf(stderr, "error allocating out_arr \n");
            exit(1);
        }
    }

    // set values for the array
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
    char* out = (char*)malloc(sizeof(char) * (num_strings + 1)); // times all strlen
    return out;
}   
