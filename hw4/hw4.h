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

