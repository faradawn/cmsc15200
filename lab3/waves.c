#include "waves.h"
#include <math.h>
#include <stdio.h>

// calculates the Euclidean distance between each pixel and the center
double dist(double x0, double y0, double x1, double y1){
    return sqrt(pow(x1-x0, 2) + pow(y1-y0, 2));
}

// generates a geometric shape with values for .ppm file  
void draw_waves(int side_length, int x_offset, int y_offset){
    
    // parameters for PPM
    printf("P3\n");
    printf("%d %d\n", side_length, side_length); 
    printf("255\n");

    // calculates center coordinates
    double xc = side_length/2+x_offset;
    double yc = side_length/2-y_offset;

    // main print for PPM
    for (int x = 0; x < side_length; x++){ // < or <=
        for (int y = 0; y < side_length; y++){
            double raw = sin(dist(x, y, xc, yc));
            int scaled =  ceil(127.5+127.5*raw);
            printf("0 0 %d ", scaled);
        }
    }

    printf("\n"); 
}