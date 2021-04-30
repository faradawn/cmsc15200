// returns the cents of maximum cents and stores the number of coins   
unsigned int find_amount_of_denomination(unsigned int cents, 
                                         unsigned int denomination, 
                                         unsigned int *num_denomination_ptr);
                                         
// returns the minimum combination of coins that adds up to the given cents
struct coins make_change(unsigned int cents);
