#include "hw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [helper function] prints the original and compressed array
void print_array(int* a, unsigned int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }    
    printf("\nlength: \n%u \n\n", len);
}
// [helper function] prints the decoded array 
void print_decode(int** a, unsigned int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *a[i]);
    }    
    printf("\nlength: \n%u \n\n", len); 
}

// [helper function] prints the array of strings
void print_str_array(char** a, unsigned int len) {
    printf("result array: \n");
    for (int i = 0; i < len; i++) {
        printf("%s, ", a[i]);
    }
    printf("\n");
} 

// [helper function] frees a two dimensional array
void free_array(char** a, unsigned int len) {
    for (int i = 0; i < len; i++) {
        free(a[i]);
    }
}


int main() {
    printf("\n=== Part 1 - Encode and Decode ===\n");
    // original array
    int original_arr[] = {1,1,2,2,2,2,2,2,4,4,4,4};
    unsigned int original_len = 12;
    printf("original array: \n");
    print_array(original_arr, original_len);

    // encode 
    unsigned int compressed_len;
    int* compressed_arr = rle_encode(original_arr, original_len, &compressed_len);
    printf("compressed array: \n");
    print_array(compressed_arr, compressed_len);
    
    // decode 
    int* decoded_arr[original_len];
    unsigned int decoded_len;
    rle_decode(compressed_arr, compressed_len, &decoded_arr, &decoded_len);
    printf("decoded array: \n");
    print_decode(&decoded_arr, decoded_len);

    // free
    free(compressed_arr);


    printf("\n=== Part 2 - Find Matches === \n");
    // raw string and matching pattern
    char* raw_str = "love alive slavic slavery notslate";
    char* pat = "l?v?";
    unsigned int num_matches;
    char** arr_matches = find_matches(raw_str, pat, &num_matches);
    print_str_array(arr_matches, num_matches);
    // free
    free_array(arr_matches, num_matches);


    printf("\n=== Part 3 - Concatenate Strings === \n");
    


    return 0;
}