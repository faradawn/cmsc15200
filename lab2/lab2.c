#include <stdio.h>
#include <math.h>
#include "lab2.h"

/* graph : draws a quadratic equation given frame size and zoom level  */
void draw_row(double a, double b, double c, double step, int xleft, int xright,
 int ybottom, int ytop, int cell_count, int rows_count){
    if (cell_count <= xright) {
        double row = rows_count * step;
        double x = cell_count * step;
        double y = a*x*x + b*x + c;
        int y_round = floor(y);
        if(y < 0) { y_round = ceil(y); }

        if (y == row || y_round == row) {
            printf("*");
        } else if (x == 0 && row == 0) {
            printf("+");
        } else if (x == 0) {
            printf("|");
        } else if (row == 0) {
            printf("-");
        } else {
            printf(" ");
        }
        draw_row(a, b, c, step, xleft, xright, ybottom, ytop, cell_count+1, rows_count);
    }   
}

/* draw_row : draws a line of asterisks and spaces */
void draw_whole(double a, double b, double c, double step, int xleft, int xright,
 int ybottom, int ytop, int x, int y){
    if (y >= ybottom) {
        draw_row(a, b, c, step, xleft, xright, ybottom, ytop, xleft, y);
        printf("\n");
        draw_whole(a, b, c, step, xleft, xright, ybottom, ytop, xleft, y-1);
    } 
 }

/* graph : checks whether the coordinate frame is legal and calls draw_whole */ 
void graph(double a, double b, double c, double step, int xleft, int xright,
 int ybottom, int ytop){
     if (xleft<=0 || xright>=0 || ytop>=0 || ybottom<=0) {
         draw_whole(a, b, c, step, xleft, xright, ybottom, ytop, xleft, ytop);
     } 
 }

