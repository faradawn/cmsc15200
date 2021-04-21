#include "lab4.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


// 1 - find max and min of an integer array
void find_min_max(int a[], int a_len, int* min_ptr, int* max_ptr){
    // initialize max and min
    *min_ptr = INT_MAX;
    *max_ptr = INT_MIN;

    // find max and min 
    for (int i = 0; i < a_len; i++) {
        if (a[i] < *min_ptr) {
            *min_ptr = a[i];
        } if (a[i] < *max_ptr) {
            *max_ptr = a[i];
        }
    }
    // recommend local varible or change value directly?
}

// 2 - make a "string" of asterisks
 char* make_star_string(int n) {
     char* arr = (char*)malloc(sizeof(char) * n); 
     if (arr == NULL) {
         fprintf(stderr, "error allocating *arr");
         exit(1);
     }

     for (int i = 0; i < n; i++){
         *(arr+i) = '*';
     }
     arr[n] = '\0';
     
     printf("%s \n", arr);

     return arr;
 }

// 3 - make a histogram array of the count of each number
int* make_histogram(int a[], int a_len, int* hist_len_ptr) {
    int i, j, temp, count;

    // sort arry a in ascending order
    for (i = 0; i < a_len-1; i++){
        for (j = i; j < a_len-1; j++){
            if (a[j] > a[j+1]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
        printf("%d ", a[i]);
    }
    printf("%d \n", a[a_len-1]);

    // determine the length of array b
    int b_len = 1;
    for (i = 0; i < a_len-1; i++){
        if (a[i+1] != a[i]){
            b_len ++;
        }
    }
    printf("array b length %d \n", b_len);

    // initialize array b with malloc
    int *b = (int*)malloc(sizeof(int) * b_len);
    if (b == NULL) {
        fprintf(stderr, "error allocating *b \n");
        exit(1);
    }
    j = 0;
    count = 0;
    for (i = 0; i < b_len; i++) {
        while (a[j] == a[j+1]) {
            j++;
            count ++;
        };
        b[i] = ++count;
        count = 0;
        j ++;
        printf(">> histgram is %d \n", b[i]);
    }

    return b;
}

// 4 - draws the historgram with length of hist_len_ptr
void print_histogram_visualization(int a[], int a_len) {
    for (int i = 0; i < a_len; i++) {
        printf("%s", make_star_string(a[i]));
        printf("\n");
    }
}

// free afterwards 
int main(){
    int a[] = {3,2,2,4,3,5};
    int b[] = {3,2,2,2,4,6,3,5,6};
    int min, max;
    int* p;
    find_min_max(b, 9, &min, &max);
    printf("max is %d \n", max);
    printf("min is %d \n", min);
    int* hist_array = make_histogram(b, 9, p);
    free(p);
    print_histogram_visualization(b, 9);
    return 0;
}