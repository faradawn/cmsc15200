// compresses the given array of positive integers
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen);
// decompresses the array of positive integers 
void rle_decode(int* in, unsigned int inlen, int** out, unsigned int* outlen);