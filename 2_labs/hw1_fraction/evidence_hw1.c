#include <stdio.h>
#include "hw1.h"

int main(int argc, char *argv[]) {
    printf("\n === testing bags_of_cat_food ===\n");
    printf("#1: 1 cat, 200g per day, 5 days => 1 bags \n >> %u\n\n",
            bags_of_cat_food(1, 200, 5));
    printf("#2: 5 cat, 200g per day, 5 days => 2 bags \n >> %u\n\n",
            bags_of_cat_food(5, 200, 5));
    printf("#3: 100 cat, 180g per day, 11 days => 50 bags \n >> %u\n\n",
            bags_of_cat_food(100, 180, 11));
    printf("#4: 100 cat, 180g per day, 200 days => 900 bags \n >> %u\n\n",
            bags_of_cat_food(100, 180, 200));
    
    printf("\n === testing fractional_part ===\n");
    printf("#1: fraction 3 / 2 => 0.5 \n >> %f \n\n",
            fractional_part(3,2));
    printf("#2: fraction 5 / 2 -> 0.5 \n >> %f \n\n",
            fractional_part(5,2));
    printf("#3: fraction 5 / 3 => 0.666... \n >> %f \n\n",
            fractional_part(5,3));
    printf("#4: fraction 10 / 10 => 0.0 \n >> %f \n\n",
            fractional_part(10, 10));

    printf("\n === testing is_buoyant ===\n");
    printf("#1: weight = 20lb, radius = 2ft => is buoyant \n >> %d \n\n",
            is_buoyant(20,2));
    printf("#2: weight = 2860.83lb, radius = 1.14ft => not buoyant \n >> %d \n\n",
            is_buoyant(2860.83,1.14));
    printf("#2: weight = 60lb, radius = 60ft => is buoyant \n >> %d \n\n",
            is_buoyant(60,60));
    printf("#2: weight = 0.27lb, radius = 0.039ft => not buoyant \n >> %d \n\n",
            is_buoyant(0.27,0.039));
    return 0;
}
