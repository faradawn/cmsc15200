#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int sqr(int a){
    return a*a;
}

void map(int (*fn)(int), int val){
    int (*f)(int) = fn;
    printf(">> %d\n", f(val));
}


int main(){
    map(sqr, 20);
}