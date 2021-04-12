#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_leap_year(int year) {
	return !(year%400) || ((year%100) && !(year%4));
}


int days_in_month(int x, int y) {
	switch (x) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			if( is_leap_year(y) )
				return 29;
			else 
				return 28;
		default:
			if(x >= 1 && x <= 12)
				return 30;
			else 
				fprintf(stderr, "std: %u", x);
				exit(1);
	}
}

int main(int arc, char** argv) {
	printf(">> %d \n", days_in_month(2, 2012));
	return 0;
}

