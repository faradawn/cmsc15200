#include <stdio.h>
#include <math.h>
#include "hw1.h"

unsigned int bags_of_cat_food(unsigned int num_cats, 
                              unsigned int grams_per_cat,
                              unsigned int num_days) {
    return ceil(grams_per_cat*num_cats*num_days/4000);
}


double fractional_part(unsigned int numerator, unsigned int denominator) {
    return (double)numerator/denominator - numerator/denominator;
}

int is_buoyant(double weight, double radius) {
    double v = 4.0/3*M_PI*pow(radius, 3);
    double F = v * 62.4;
    return F >= weight;
}
