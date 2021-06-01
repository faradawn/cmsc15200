#include <stdio.h>
#include <stdlib.h>

void getASCII(char c){
    printf("direct print: %d\n", c);
    printf("cast to int: %d\n", (int)c);
    int n = 0;
    n += c;
    printf("initialize with int: %d\n", n);

}

unsigned int toInteger(char c){
    printf("ASCII of input: %d\n", c);
    int n = (int)c;
    return c-48;
}

unsigned int toInteger2(char c){
    printf("ASCII of input: %d\n", c);
    int n = (int)c;
    return c-48;
}

int main(){
    
    while(1){
        char c,r;
        printf("enter char from 1-10: ");
        scanf("%c%c*c", &c, &r);
        printf("print value: %u, %u\n", toInteger(c), toInteger2(r));
    }
}

