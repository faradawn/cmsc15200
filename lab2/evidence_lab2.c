#include "lab2.h"
#include <stdio.h>
#include <stdlib.h>


/* 
Graph 1:
y = 0.1x^2 + 2
left, right, bottom, top = (-20, 20, -1, 20)
step = 1
*/

/* 
Graph 2:
y = x^2
left, right, bottom, top = (-3, 4, -1, 16)
step = 0.5
*/

/*
Graph 3:
y = -0.3x^2 -12x - 120
left, right, bottom, top = (-40, 0, -20, 0)
step = 2
*/

/*
Graph 4: 
y = 0.25x^2 - 10.05x + 105
left, right, bottom, top = (0, 40, 0, 20)
*/


int main(int argc, char *argv[]) {
    printf("Graph 1: y = 0.1x^2 + 2, step = 1 \n"); 
    graph(0.1, 0, 2, 1, -20, 20, -1, 20);
    printf("Graph 2: y = x^2, step = 0.5 \n");
    graph(1, 0, 0, 0.5, -3, 4, -1, 16);
    printf("Graph 3: y = -0.3x^2 -12x - 120, step = 2 \n");
    graph(-0.3, -12, -120, 2, -40, 0, -20, 0);
    printf("Graph 4: y = 0.25x^2 - 10.05x + 105, step = 1 \n");
    graph(0.25, -10.05, 105, 1, 0, 40, 0, 20);
    return 0;
}