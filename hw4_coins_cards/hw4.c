#include "hw4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// part1: coins

// 1-1: returns the cents of maximum cents and stores the number of coins   
unsigned int find_amount_of_denomination(unsigned int cents, 
                                         unsigned int denomination, 
                                         unsigned int *num_denomination_ptr) {
                                             *num_denomination_ptr = cents / denomination;
                                             return *num_denomination_ptr * denomination;
                                         }
// 1-2: returns the minimum combination of coins that adds up to the given cents
struct coins make_change(unsigned int cents) {
    struct coins coin;
    unsigned int num_denomination, cents_remaining;

    cents_remaining = cents - find_amount_of_denomination(cents, QUARTERS, &num_denomination);
    coin.quarters = num_denomination;

    cents_remaining = cents_remaining - find_amount_of_denomination(cents_remaining, DIMES, &num_denomination);
    coin.dimes = num_denomination;

    cents_remaining = cents_remaining - find_amount_of_denomination(cents_remaining, NICKELS, &num_denomination);
    coin.nickels = num_denomination;

    cents_remaining = cents_remaining - find_amount_of_denomination(cents_remaining, PENNIES, &num_denomination);
    coin.pennies = num_denomination;

    return coin;
}


// part2: colors


// 2-1: return negative colors subtracted from the maximum color intensity
struct color* negative(struct color* c){
    // define the maximum color intensity    
    unsigned char max_intensity = 255;

    // malloc the output color struct
    struct color *out_color = (struct color*)malloc(sizeof(struct color));
    if(out_color == NULL) {
        fprintf(stderr, "error mallocing negative color struct");
        exit(1);
    }

    out_color->red = max_intensity - c->red;
    out_color->green = max_intensity - c->green;
    out_color->blue = max_intensity - c->blue;

    return out_color;
}

// 2-2: return greyscale colors using a weighted average formula
struct color* greyscale(struct color* c) {
    // calculate the weighted average
    unsigned char weighted_avg = (77*c->red+150*c->green+29*c->blue)/256;

    // malloc the output color struct
    struct color *out_color = (struct color*)malloc(sizeof(struct color));
    if(out_color == NULL) {
        fprintf(stderr, "error mallocing greyscale struct");
        exit(1);
    }

    out_color->red = weighted_avg;
    out_color->green = weighted_avg;
    out_color->blue = weighted_avg;
    
    return out_color;
}



// part3: poker cards

// [helper function: print the rank number]
void print_rank(unsigned char n) {
    if (n == 1){
        printf("Ace");
    }
    for (unsigned char i = 2; i <= n; i++) {
        if(i == n) {
            printf("%u", i);
        }
    }
}

// [helper function: print the suit name]
void print_suit(enum suit suit){
    switch (suit)
    {
    case SPADES:
        printf("SPADES");
        break;
    case HEARTS:
        printf("Hearts");
        break;
    case CLUBS:
        printf("Clubs");
        break;
    default:
        printf("Diamonds");
        break;
    }
}
// [helper function: print face text]
void print_face(enum face face){
    switch (face)
    {
    case JACK:
        printf("Jack");
        break;
    case QUEEN:
        printf("Queen");
        break;
    default:
        printf("King");
    }
}


// 3-1: check if all cards in the array are black
int all_black(struct card* cards, unsigned int ncards) {
    for (int i = 0; i < ncards; i++) {
        if(cards[i].type == JOKER){
            return 0;
        } else if (cards[i].type == FACE) {
            if(cards[i].rs.f.suit == HEARTS || cards[i].rs.f.suit == DIAMONDS) {
                return 0;
            }
        } else {
            if(cards[i].rs.p.suit == HEARTS || cards[i].rs.p.suit == DIAMONDS) {
                return 0;
            }
        }
    }
    return 1;
}

// 3-2: display what the given card
void card_show(struct card c) {
    if (c.type == JOKER) {
        printf("Joker");
    } else if (c.type == FACE) {
        print_rank(c.rs.f.rank);
        printf(" of ");
        print_suit(c.rs.f.suit);
    } else {
        print_rank(c.rs.p.rank);
        printf(" of ");
        print_suit(c.rs.p.suit);
    }

}

// 3-3: check if the two cards are identical 
int cards_equal(struct card c1, struct card c2){
    if (c1.type == JOKER) { // both types are JOKER 
        return 1; // assume only one type of joke
    } else if (c1.type == FACE) { // both types are FACE
        if(c1.rs.f.suit == c2.rs.f.suit){
            if(c1.rs.f.rank == c2.rs.f.rank){
                return 1;
            }
        } 
    } else { // both types are PIP
        if(c1.rs.p.suit == c2.rs.p.suit) {
            if(c1.rs.p.rank == c2.rs.p.rank) {
                return 1;
            } 
        } 
    }
    // if no match, return false 
    return 0; 
}

// 3-4: computes the sum of the card array
unsigned int sum_cards(struct card* cards, unsigned int ncards) {
    unsigned int i, count = 0;
    for (i = 0; i < ncards; i++){
        switch (cards[i].type)
        {
        case FACE: // value of FACE = 10
            count += 10;
            break;
        case PIP: // value of PIP = rank
            count += cards[i].rs.p.rank;
            break;
        default: // value of JOKER = 0
            break; 
        }
    }
    return count;
}