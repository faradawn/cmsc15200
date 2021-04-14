#include "waves.h"
#include <stdio.h>

// tests for dist function
int main(int argc, char *argv[]){
    printf("=== Tests for function dist() ===\n");
    printf("distance between (3, 4) (0, 0) is 5.00 \n  >> %lf\n", dist(3, 4, 0, 0));
    printf("distance between (3, 4) (-1, -1) is 6.40 \n  >> %lf\n", dist(3, 4, -1, -1));
    printf("distance between (-0.1, -0.5) (2.3, 7.9) is 8.74 \n  >> %lf\n", dist(-0.1, -0.5, 2.3, 7.9));
    printf("distance between (254, 0) (100, 100) is 183.62 \n  >> %lf\n", dist(254, 0, 100, 100));
    return 0;
}