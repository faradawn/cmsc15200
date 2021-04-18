#include "hw2.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 1 - returns the initial letter of a corresponding 0-9 digit
unsigned char first_letter(unsigned int digit){
    switch(digit) {
        case 1:
            return 'o';
        case 2:
        case 3:
            return 't';
        case 4:
            return 'f';
        case 5:
            return 'f';
        case 6:
        case 7:
            return 's';
        case 8:
            return 'e';
        case 9: 
            return 'n';
        default:
            if (digit<0 || digit>9) {
                fprintf(stderr, "Input not within 0-9 %u", digit);
			    exit(1);
            } else {
                return 'z';
            }
    }
}

// 2 - approximates pi with circle's area in a grid
double calc_pi(unsigned long long int nslices) {

    double STEP = (double) 1 / nslices;
    long long int count_pt = 0;

    for (long long int i = 0; i < nslices; i ++){
        double x = i*STEP;
        for (long long int j = 0; j < nslices; j ++){
            double y = j*STEP;
            if (x*x+y*y <= 1) {
                count_pt ++;           
            }
        }
    }
    double circle_area = 4 * (double) count_pt / (nslices*nslices);
    return circle_area;
}

// 3 - computes the square root of s using the Bakhshali sequence
double bakhshali(double s, double guess, double epsilon, unsigned int max_iters){
    double x = guess;
    double an;
    double bn;
    while (max_iters>0) {
        if (fabs(x*x-s) < epsilon) {
            break;
        }
        an = (s-x*x)/(2*x);
        bn = x+an;
        x = bn - an*an/(2*bn);
        max_iters--;
    }
    return x;
}

void print_line(unsigned int length){
    for (int i = 0; i < length; i ++){
        printf("*");
    }
    printf("\n");
}

// 4- draws a half-filled square with given side length and target part
void half_filled_square(unsigned int side_length, int upper_right){
    // error if not 1 or 0
    print_line(side_length);
    for (int i = 0; i < side_length-2; i++) {
        printf("*");
        for (int j = 0; j < side_length-2; j++) {
            if (upper_right) {
                if (j <= i){
                    printf(" ");
                } else {
                    printf("*");
                }
            } else {
                if (j < i) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("*\n");
    }
    print_line(side_length);

}

int main(){
    printf("\n final %f \n", bakhshali(256, 1, 0.1, 1));
    half_filled_square(10, 1);
    return 0;
    
}