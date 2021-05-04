// defining structs 
struct coins {
   unsigned int quarters; // 25 cents
   unsigned int dimes; // 10 cents
   unsigned int nickels; // 5 cents
   unsigned int pennies; // 1 cent
};

// define each domination's value 
enum coin_values {
    QUARTERS = 25,
    DIMES = 10,
    NICKELS = 5,
    PENNIES = 1
};

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


// returns the cents of maximum cents and stores the number of coins   
unsigned int find_amount_of_denomination(unsigned int cents, 
                                         unsigned int denomination, 
                                         unsigned int *num_denomination_ptr);
// returns the minimum combination of coins that adds up to the given cents
struct coins make_change(unsigned int cents);


// returns negative colors subtracted from the maximum color intensity
struct color* negative(struct color* c);
// returns greyscale colors using a weighted average formula
struct color* greyscale(struct color* c);


// checks if all cards are black
int all_black(struct card* cards, unsigned int ncards);
// displays what the given card struct holds
void card_show(struct card c);
// checks if the two cards are identical
int cards_equal(struct card c1, struct card c2);
// computes the sum of the card array
unsigned int sum_cards(struct card* cards, unsigned int ncards);

