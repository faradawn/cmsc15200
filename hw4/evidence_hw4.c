#include "hw4.h"
#include <stdio.h>

int main() {
    printf("=== Part 1 - Find the Amount of Denominations === \n");
    unsigned int num_denomination;
    printf("value in cents: %u \n", find_amount_of_denomination(117, 25, &num_denomination));
    printf("number of denomination: %u \n", num_denomination);
    
}
