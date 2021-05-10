#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// show function

int main(){
    int arr1[2][3] = {{1,2,3},{1,2,3}};
    printf("%d \n", arr1[1][0]);
    printf("%d \n", *(arr1+ 1));


}

