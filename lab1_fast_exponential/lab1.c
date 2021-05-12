#include "lab1.h"

// linear time exponentiation
long long int expt(int a, unsigned int n) {
    if (n == 0){
        return 1;
    } else {
        return a * expt(a, n-1);
    }
}

// successive squaring
long long int ss(int a, unsigned int n) {
    if (n == 0) {
        return 1;
    } else if (n%2 == 0) {
        return ss(a, n/2) * ss(a, n/2);
    } else {
        return a * ss(a, n-1);
    }
}

// fast exponentiation modulo m
int ssm(int a, unsigned int n, unsigned int m) {
    if (n == 0) {
        return 1%m;
    } else if (n == 1) {
        return a%m;
    } else if (n%2 == 0) {
        return (ssm(a, n/2, m)%m * ssm(a, n/2, m))%m;
    } else {
        return (a * ssm(a, n-1, m))%m;
    }
}
