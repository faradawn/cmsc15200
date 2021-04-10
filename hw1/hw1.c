#include <stdio.h>
#include <math.h>
#include "hw1.h"

unsigned int bags_of_cat_food(unsigned int num_cats, 
                              unsigned int grams_per_cat,
                              unsigned int num_days) {
    return ceil(grams_per_cat*num_cats*num_days/4000);
}


double fractional_part(unsigned int numerator, unsigned int denominator) {
    return numerator/denominator;
}

int is_buoyant(double weight, double radius) {
    double v = 4/3*M_PI*pow(radius, 3);
    printf("%lf", v);
    double F = v * 62.4;
    return F > weight;
}

// int main() {
//     printf("=== testing bags_of_cat_food ===\n");
//     printf("#1: 5 cats, 200g per day, 5 days -> 5 bags \n >> ans: %u bags\n",
//             bags_of_cat_food(5, 500, 5));
    
//     printf("=== testing fractional_part ===\n");
//     printf("#1: fraction 2 / 3 -> 0.5  \n >> ans: %llf \n",
//             fractional_part(2,3));

//     printf("=== testing is_buoyant ===\n");
//     printf("#1: weight = 20, radius = 5 -> is buoyant \n >> ans: %d \n",
//             is_buoyant(20,5));

//     return 1;
// }