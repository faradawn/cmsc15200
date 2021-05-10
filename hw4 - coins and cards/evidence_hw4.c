#include "hw4.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    // part 1: coins 
    printf("\n=== Part 1 - Find the Amount of Denominations === \n");

    unsigned int num_denomination;
    printf("input cents: 117, type of coin: quater \n ");
    printf("output cents: %u\n", find_amount_of_denomination(117, 25, &num_denomination));
    printf("number of denomination: %u \n", num_denomination);

    // part 2: colors 
    printf("\n=== Part 2 - Negative and Greyscale Colors === \n");

    // original color
    struct color original_color = {182, 145, 0};
    printf("original color: (182, 145, 0) \n");

    // negative color
    struct color* negative_color = negative(&original_color);
    printf("negative color: (%u, %u, %u) \n", 
        negative_color->red, negative_color->green, negative_color->blue);

    // greyscale color
    struct color* grey_color = greyscale(&original_color);
    printf("greyscale color: (%u, %u, %u) \n",
        grey_color->red, grey_color->blue, grey_color->green);


    // part 3: poker
    printf("\n=== Part 3 - Poker Cards === \n");

    struct pip_card pip1 = {5, CLUBS};
    struct face_card face1 = {QUEEN, HEARTS};
    union rank_suit u1, u2, u3;
    u1.p = pip1;
    u2.f = face1;
    u3.p = pip1;

    struct card card1 = {PIP, u1};
    struct card card2 = {FACE, u2};
    struct card card3 = {PIP, u3};

    struct card card_arr1[] = {card1, card2, card3};
    struct card card_arr2[] = {card1, card3};
    printf("card_arr1 = {5 of Clubs, Queen of Hearts, 5 of Clubs}\n");
    printf("card_arr2 = {5 of Clubs, 5 of Clubs}\n");
    printf("check card_arr1 all black: %d \n", all_black(card_arr1, 3));
    printf("check card_arr2 all black: %d \n", all_black(card_arr2, 2));
    printf("\nshow card1 and card3: \n");
    card_show(card1);
    printf(", ");
    card_show(card3);
    printf("\ncheck card1 and card3 equal: %d \n", cards_equal(card1, card3));

    printf("\nsum of card_arr1: %u \n", sum_cards(card_arr1, 3));
    printf("sum of card_arr2: %u \n", sum_cards(card_arr2, 2));
    


}
