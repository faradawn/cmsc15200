#include <stdio.h>
#include <stdlib.h>

unsigned int setOne(unsigned int num, unsigned int i){
    if((num>>i & 1) == 0){
        return num | (1 << i);
    } else {
        return num;
    }
}

unsigned int setZero(unsigned int num, unsigned int i){
    if((num>>i & 1) == 1){
        return num ^ (1 << i);
    } else {
        return num;
    }
}

int main(){
    printf("%u\n", setOne(0, 2));
}