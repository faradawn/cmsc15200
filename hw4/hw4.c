#include "hw4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coins {
   unsigned int quarters; // 25 cents
   unsigned int dimes; // 10 cents
   unsigned int nickels; // 5 cents
   unsigned int pennies; // 1 cent
};

enum coin_values {
    QUARTERS = 25,
    DIMES = 10,
    NICKELS = 5,
    PENNIES = 1
};

unsigned int find_amount_of_denomination(unsigned int cents, 
                                         unsigned int denomination, 
                                         unsigned int *num_denomination_ptr) {
                                             *num_denomination_ptr = cents / denomination;
                                             return *num_denomination_ptr * denomination;
                                         }

struct coins make_change(unsigned int cents) {
    struct coins coin;
    unsigned int num_denomination, cents_remaining;
    // convert into loop
    cents_remaining = cents - find_amount_of_denomination(cents, QUARTERS, &num_denomination);
    coin.quarters = num_denomination;
    printf("number of quarters: %u \n", coin.quarters);
    printf("%u \n", cents_remaining);

    cents_remaining = cents_remaining - find_amount_of_denomination(cents_remaining, DIMES, &num_denomination);
    coin.dimes = num_denomination;
    printf("number of dimes: %u \n", coin.dimes);
    printf("%u \n", cents_remaining);

    cents_remaining = cents_remaining - find_amount_of_denomination(cents_remaining, NICKELS, &num_denomination);
    coin.nickels = num_denomination;
    printf("number of nickles: %u \n", coin.nickels);
    printf("%u \n", cents_remaining);

    cents_remaining = cents_remaining - find_amount_of_denomination(cents_remaining, PENNIES, &num_denomination);
    coin.pennies = num_denomination;
    printf("number of pennies: %u \n", coin.pennies);
    printf("%u \n", cents_remaining);

    return coin;
}

int main () {
    struct coins coin = make_change(117);
}
