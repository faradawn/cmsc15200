#include "waves.h"
#include <math.h>
#include <stdio.h>


// calculates the Euclidean distance between each pixel and the center
double dist(double x0, double y0, double x1, double y1){
    return sqrt(pow(x1-x0, 2) + pow(y1-y0, 2));
}

// generates a geometric shape with values for .ppm file  
void draw_waves(int side_length, int x_offset, int y_offset,
    double r_scale, double g_scale, double b_scale){

    // declare variables
    unsigned char red, green, blue; // output rgb values
    double d; // distance
    unsigned char max_color_value = 255;
    double color_half = max_color_value / 2.0;

    // calculate center coordinates
    double xc = side_length/2 + x_offset;
    double yc = side_length/2 - y_offset;
    
    // print header parameters for PPM
    printf("P3\n");
    printf("%d %d\n", side_length, side_length); 
    printf("%u\n", max_color_value);


    // print rgb values for PPM
    for (int x = 0; x < side_length; x++){ 
        for (int y = 0; y < side_length; y++){
            d = dist(x, y, xc, yc);
            red = ceil(color_half + color_half * sin(r_scale * d));
            green = ceil(color_half + color_half * sin(g_scale * d));
            blue = ceil(color_half + color_half * sin(b_scale * d));
            printf("%u %u %u ", red, green, blue);
        }
    }

    printf("\n"); 
}