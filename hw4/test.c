#include <stdio.h>

void print_rank(unsigned char n) {
    for (unsigned char i = 1; i <= n; i++) {
        if(i == n) {
            printf("%u", i);
        }
    }
}

int main(){
    print_rank(1);

}
