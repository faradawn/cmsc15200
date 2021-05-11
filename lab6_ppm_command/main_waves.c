#include "waves.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// draws the waves
int main(int argc, char **argv) {
    // declare default values for draw_wave 
    int length = 200;
    int x_offset = 0, y_offset = 0;
    double r_scale = 1.0, g_scale = 1.0, b_scale = 1.0;

    // loops through the input arguments
    if (argc > 0) {
        for (int i = 0; i < argc; i++) {
            if(strcmp(argv[i], "-s") == 0){
                length = atoi(argv[i+1]);
            } else if(strcmp(argv[i], "-r") == 0) {
                r_scale = atof(argv[i+1]);
            } else if(strcmp(argv[i], "-g") == 0) {
                g_scale = atof(argv[i+1]);
            } else if(strcmp(argv[i], "-b") == 0) {
                b_scale = atof(argv[i+1]);
            } else if(strcmp(argv[i], "-x") == 0) {
                x_offset = atoi(argv[i+1]);
            } else if(strcmp(argv[i], "-y") == 0) {
                y_offset = atof(argv[i+1]);
            }
        }
    }

    // draw the wave 
    draw_waves(length, x_offset, y_offset, r_scale, g_scale, b_scale);
    return 0;
    
}