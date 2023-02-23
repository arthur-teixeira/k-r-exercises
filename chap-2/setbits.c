#include <stdio.h>

int setbits(int x, int p, int n, int y);
int main() {
    const int result = setbits(218, 3, 3, 170);
    printf("result is %d\n", result);
}

int setbits(int x, int p, int n, int y) {
    int bitmask = ~0; // 1111 1111
    bitmask <<= n; //1111 1000, shifts the mask to get n zeros at the end
    bitmask = ~bitmask; //0000 0111, inverts to get correct mask

    y &= bitmask; //gets rightmost n bits in y
    y <<= p; //shifts y by p bits to place it in correct position

    bitmask <<= p; //shifts bitmask by p to place it in correct position to mask x
    bitmask = ~bitmask; //inverts mask to get correct bits from x
    x &= x; //gets other bits fom x
    return y | x; //merge;
}
