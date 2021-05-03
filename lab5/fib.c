#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int increase(int n) {
    for (int i = 0; i < 10; i++){
    if (n%2 == 0) {
        n += 1;
    } else {
        n += 1;
    }
    }
    return n;
}

int main(){
    increase(1);
}