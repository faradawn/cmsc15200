#include "hw4.h"
#include <stdio.h>
#include <stdlib.h>

struct color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

enum face {
    JACK, QUEEN, KING
};

enum suit {
    SPADES, HEARTS, CLUBS, DIAMONDS 
};

enum card_type {
    FACE, PIP, JOKER
};

struct face_card { 
    enum face rank;
    enum suit suit;
};

struct pip_card { 
    unsigned char rank;
    enum suit suit;
};

union rank_suit { 
    struct face_card f;
    struct pip_card p; 
};

struct card {
    enum card_type type;
    union rank_suit rs; 
};

int main() {

    // part 1
    printf("=== Part 1 - Find the Amount of Denominations === \n");

    unsigned int num_denomination;
    printf("value in cents: %u \n", find_amount_of_denomination(117, 25, &num_denomination));
    printf("number of denomination: %u \n", num_denomination);

    // part 2
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




    // part 3 
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

    printf("%d \n", all_black(card_arr1, 3));
    printf("%d \n", all_black(card_arr2, 2));

    card_show(card1);
    printf("\n card equal: %d \n", cards_equal(card1, card3));

    printf("sum: %u \n", sum_cards(card_arr1, 3));
    printf("sum: %u \n", sum_cards(card_arr2, 2));
    


}
