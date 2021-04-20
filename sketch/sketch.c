#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int arc, char** argv) {
    short a[] = {1, 2 ,3};
    a[0] = 4;
    *(a+1) = 5;
    printf(">> %hd \n", a[0]);
    printf(">> %hd \n", a[1]);
	return 0;
}

