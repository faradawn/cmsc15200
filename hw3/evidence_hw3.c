#include "hw3.h"
#include <stdio.h>
#include <stdlib.h>

// prints the original and compressed array
void print_array(int* a, unsigned int len) {
    printf("    ");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }    
    printf("\n    length: %u \n\n", len);
}
// prints the decoded array 
void print_decode(int** a, unsigned int len) {
    printf("    ");
    for (int i = 0; i < len; i++) {
        printf("%d ", *a[i]);
    }    
    printf("\n    length: %u \n\n", len); 
}


int main() {
    printf("\n=== Encode and Decode ===\n");
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

    return 0;
}