#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n === 1 - find min and max === \n");
    int min, max;
    int a[] = {3,1,4,6,2,2,3,4,3,4,4};
    int a_len = 11;
    find_min_max(a, a_len, &min, &max);
    printf("min and max: %d, %d \n", min, max);

    printf("\n === 2 - make star string === \n");
    char* test_star = make_star_string(5);
    printf("star string: %s \n", test_star);
    free(test_star);

    printf("\n === 3 - make histogram === \n");
    int hist_len;
    int* test_hist = make_histogram(a, a_len, &hist_len);
    printf("histgram: ");
    for (int i = 0; i < hist_len; i++) {
        printf("%d ", test_hist[i]);
    }

    printf("\n\n === 4 - print histogram graph === \n");
    print_histogram_visualization(test_hist, hist_len);
    free(test_hist);

}