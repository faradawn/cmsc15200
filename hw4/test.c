#include <stdio.h>



// struct card* build_card_array() {
//     struct pip_card pip1 = {5, CLUBS};
//     struct face_card face1 = {QUEEN, HEARTS};
//     union rank_suit u1;
//     u1.p = pip1;
//     u1.f = face1; 

//     struct face_card face2 = {KING, CLUBS};
//     struct pip_card pip2 = {10, SPADES};
//     union rank_suit u2 = {face1, pip2};
    
//     struct card card1 = {FACE, u1};
//     struct card card2 = {PIP, u1};
//     struct card card3 = {FACE, u2};
//     struct card card4 = {PIP, u2};
//     struct card card_array[] = {card1, card2, card3, card4};

//     return card_array;
// }

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
