// counts the number of unique elements in an array
int count_unique_elements(int in[], unsigned int inlen);
// compresses the given array of positive integers
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen);
// decompresses the array of positive integers 
void rle_decode(int* in, unsigned int inlen, int** out, unsigned int* outlen);
// finds the matches in string and puts them into an array
char** find_matches(char* str, char* pat, unsigned int* nmatches);
// concatenates an array of strings and inserts spaces between words
char* concat_strings(char** strings, unsigned int num_strings);

