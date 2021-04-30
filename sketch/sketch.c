#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* build_array(){
    unsigned int len = 2;
    int* out = (int*)malloc(sizeof(int)*len);
    out[0] = 0;
    out[1] = 1;
    int *ptr = malloc(sizeof(int)*1);
    out[2] = 2;
    out[3] = 3;
    printf("address: %d \n", out);
    printf("address: %d \n", out+1);
    printf("address: %d \n", out+2);
    printf("address: %d \n", ptr);

    printf("print 3: %d \n", out[2]);
    return out;



}

int main () {
    int* arr1 = build_array();
    printf("arr[2]: %d \n", arr1[2]);
    printf("arr[2]: %d \n", arr1[3]);
    return 0;
}