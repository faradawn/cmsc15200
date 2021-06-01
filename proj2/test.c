#include <stdio.h>
#include <stdlib.h>

void getASCII(char c){
    printf("direct print: %d\n", c);
    printf("cast to int: %d\n", (int)c);
    int n = 0;
    n += c;
    printf("initialize with int: %d\n", n);

}

// outputs the ASCII value
int printASCII(char c){
    return (int)c;
}

int main(){  
    while(1){
        char ch1,ch2;
        printf("enter two ones: ");
        scanf("%c%c%*c", &ch1, &ch2);
        printf("print ASCII: %d, %d\n", (int)ch1, (int)ch2);
        // input: 1, 1 , output ASCII becomes 49, 10 
        // why the second output is 10?
    }
}

