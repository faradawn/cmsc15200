// finds the maximum and minimum of an array of positive integers
void find_min_max(int a[], int a_len, int* min_ptr, int* max_ptr);

// returns the pointer of an allocated string of stars 
char* make_star_string(int n);

// returns the pointer of an allocated histogram array
int* make_histogram(int a[], int a_len, int* hist_len_ptr);

// prints the graph of histogram
void print_histogram_visualization(int a[], int a_len);
