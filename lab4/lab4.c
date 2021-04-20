// #include "lab4.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void find_min_max(int a[], int a_len, int* min_ptr, int* max_ptr){
    *min_ptr = a[0];
    *max_ptr = a[a_len];
    // how to use limits.h ?
    for (int i = 0; i < a_len; i++) {
        if (a[i] < *min_ptr) {
            *min_ptr = a[i];
        }
    }
    for (int j = a_len-1; j >= 0; j--) {
        if (a[j] > *max_ptr) {
            *max_ptr = a[j];
        }
    }
}

 char* make_star_string(int n) {
     char* arr = (char*)malloc(n*sizeof(char)); 
     for (int i = 0; i < n; i++){
         *(arr+i) = '*';
     }
     return arr;
 }

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

    // initialize array b with zeors 
    int *b = (int*)malloc(b_len*sizeof(int)); 
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

    int hey = 1;
    int* p = &hey;
    return p;
}

int main(){
    int a[] = {3,2,2,4,3,5};
    int b[] = {3,2,2,2,4,6,3,5,6};
    int min, max;
    int* p;
    find_min_max(b, 9, &min, &max);
    printf("max is %d \n", max);
    printf("min is %d \n", min);
    make_histogram(b, 9, p);
    return 0;
}