#include "waves.h"
#include <math.h>
#include <stdio.h>

double dist(double x0, double y0, double x1, double y1){
    return sqrt(pow(x1-x0, 2) + pow(y1-y0, 2));
}

void draw_waves(int side_length, int x_offset, int y_offset){
    
    // parameters for PPM
    printf("P3\n");
    printf("%d 1\n", side_length); //todo
    printf("255\n");

    printf("\n"); 

    
}

int main(){
    printf("%lf", dist(3, 4, 0, 0));
    return 0;
}