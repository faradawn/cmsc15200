#include <stdio.h>

double sequence(int n) {
	if (n == 1){
		printf("a1 is 1 \n");
		return 1;
	} else {
		double a =  (float)1/(1+2*sequence(n-1));
		printf("a%d is %llf \n", n, a);
		return a;
	}
}

int main(int arc, char** argv) {
	sequence(6);
	return 0;
}
