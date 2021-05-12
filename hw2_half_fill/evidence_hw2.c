#include "hw2.h"
#include <stdio.h>

int main() {
    printf("\n === Test 1: Printing First Letter === \n");
    printf("digit 1's first letter is z \n >> %c \n", first_letter(0));
    printf("digit 6's first letter is s \n >> %c \n", first_letter(6));
    printf("digit 7's first letter is s \n >> %c \n", first_letter(6));
    // raises error if digit > 9 or < 0

    printf("\n === Test 2: Calculating Pi === \n");
    printf("[The outputs are expected to range from 3 to 3.2 \n");
    printf("and approaches 3.1415... as number of slices increases.]\n");
    printf("number of slices = 1 \n >> %lf \n", calc_pi(2));
    printf("number of slices = 3 \n >> %lf \n", calc_pi(3));
    printf("number of slices = 10 \n >> %lf \n", calc_pi(10));
    printf("number of slices = 100 \n >> %lf \n", calc_pi(100));
    printf("number of slices = 1000 \n >> %lf \n", calc_pi(1000));


    printf("\n === Test 3: Calculating Root === \n");
    printf("root of 16, guess = 3, epsilon = 0.01, max_iter = 10\n >> %lf\n",
        bakhshali(16, 3, 0.01, 10));
    printf("root of 16, guess = 10, epsilon = 0.01, max_iter = 3\n >> %lf\n",
        bakhshali(16, 10, 0.01, 10));
    printf("root of 255, guess = 20, epsilon = 0.01, max_iter = 10\n >> %lf\n",
        bakhshali(255, 20, 0.01, 10));
    printf("root of 255, guess = -20, epsilon = 0.01, max_iter = 20\n >> %lf\n",
        bakhshali(255, -20, 0.01, 20));
    printf("root of 1024, guess = 0, epsilon = 0.005, max_iter = 10\n >> %lf\n",
        bakhshali(1024, 1, 0.005, 10));
    printf("root of 1024, guess = 100, epsilon = 0.005, max_iter = 5\n >> %lf\n",
        bakhshali(1024, 100, 0.005, 10));
    // raises error if s < 0 or epsilon < 0

    printf("\n === Test 4: Drawing Half-Filled Square === \n");
    printf("draw 10, 1 \n");
    half_filled_square(10, 1);
    printf("draw 10, 0 \n");
    half_filled_square(10, 0);
    printf("draw 19, 1 \n");
    half_filled_square(19, 0);
    printf("draw 19, 0 \n");
    half_filled_square(19, 1);
    // raises error if upper_right is not 0 or 1

    return 0;
}
    
    
    
