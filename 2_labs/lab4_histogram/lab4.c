#include "lab4.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// 1 - find max and min of an integer array
void find_min_max(int a[], int a_len, int* min_ptr, int* max_ptr){
    // initialize max and min
    // is it better to create local varibles?
    *min_ptr = INT_MAX;
    *max_ptr = INT_MIN;

    // find max and min 
    for (int i = 0; i < a_len; i++) {
        if (a[i] < *min_ptr) {
            *min_ptr = a[i];
        } if (a[i] > *max_ptr) {
            *max_ptr = a[i];
        }
    }
}

// 2 - make a "string" of asterisks
 char* make_star_string(int n) {
     char* str = (char*)malloc(sizeof(char) * n); 
     if (str == NULL) {
         fprintf(stderr, "error allocating *arr");
         exit(1);
     }

     for (int i = 0; i < n; i++){
         *(str+i) = '*';
     }

     str[n] = '\0';
     return str;
 }

// 3 - make a histogram array of the count of each number
int* make_histogram(int a[], int a_len, int* hist_len_ptr) {
    int max, min;
    find_min_max(a, a_len, &min, &max);
    *hist_len_ptr = max - min + 1;

    // initialize histogram array with max-min length
    int* arr = (int*)malloc(sizeof(int) * *hist_len_ptr);
    if (arr == NULL) {
        fprintf(stderr, "error allocating histogram arr \n");
        exit(1);
    } 

    // make the histogram array
    for (int i = 0; i < *hist_len_ptr; i++) {
        for (int j = 0; j < a_len; j++) {
            if (a[j] == min+i) {
                arr[i] ++;
            }    
        }
    }

    return arr;
}

// 4 - draws the historgram with length of hist_len_ptr
void print_histogram_visualization(int a[], int a_len) {
    for (int i = 0; i < a_len; i++) {
        printf("%s", make_star_string(a[i]));
        printf("\n");
    }
}
