#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* errors:
	"missing separator:" 
        tab, not 4 space, 
        (optional: tab detection off)
	"symbol undefined:"
        use make file, compile two files together 

    "Segmentation Fault 11":
        int i, j; -> not zero!!!!
        int* array = mallc
    "print only first string love"
        double space between ?
*/


/* [Week 5] lecture 5 - functions */

// declare function first 
int sqr(int a, int b);

int fn2(int c){
	int d = sqr(c, 2);
	return d;
}

int sqr(int a, int b) {
	return pow(a, b);
}

// standard error
// fprintf(stderr, "error: %d", digit);


// leap year switch
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


/* lecture 6 - while, for, do */
// do and input 
int react_to_key(){
	int x;
	int count = 3;
	int ans = 1;
	do {
		printf("input please: \n");
		scanf("%d", &x);
		count --;
		
	} while (count > 0);
	return ans*x;
}

// do loop: continue and break 
int is_prime(int n) {
    for (int i = 2; i < n; i ++) {
        if (n%2 == 0){
            return 0;
        }
    }
    return 1;
}
void mth(){
    	unsigned int M = 2, n = 0, count = 0;
    do {
        n ++;
        if (!is_prime(n)) {
            continue;
        } else {
            if (++count == M) {
                break;
            }
        }
    } while (1);
    printf(">> %d \n", n);
}


	

// Week 3
// lecture 7 - for loop 
/* 8 bits = 1 bytes (IBM groups 8 1/0 into byte)
    every char = 1 byte
    access


*/
void print_pointer() {

	int i = 7; // original value
    int* address = &i; // p points to i's address
    // int val = address; // extracts value 
    *address = 13; // sets i to 13
    printf(">> %p", address);
    // * operator is "dereferencing"
    int a = 1;
    int *ap = &a;
}

// generate name
void generate_name(int a, char* name, int* age) {
    *name = 'a';
    *age = a;
}
void name_main() {
    char name;
    int age;
    generate_name(10, &name, &age);
    printf(">> %c, %d", name, age);
}

// correct returning address
short* func(){
    short* p = (short*)malloc(sizeof(short));
    if (p == NULL) {
        fprintf(stderr, "address not allocated \n");
        exit(1);
    }
    *p = 1;
    return p;
}

// array and pointer as array
void array1() {
    short a[] = {1, 2 ,3};
    a[0] = 4;
    *(a+1) = 5;
    printf(">> %hd \n", a[0]);
    printf(">> %hd \n", a[1]);
}

// strings from Morgan
void string_stuff(){
    char s1[] = "abc"; // "" easy declare, <string.h>,
    // s1[3] = null, s1[4] out of bound
    char s2[] = {'a','b','c','\0'};
}

// hard array allocation !
void pointer_array(){
    int *ptr[3];    
    int a = 1;
    ptr[0] = &a;
    printf("%d \n", *ptr[0]);
}


// debugger lldb
/*
 run
 bt - backtrace
 breakpoint set -f fib.c -l 23
 
 */
