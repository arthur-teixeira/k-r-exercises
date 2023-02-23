#include <stdio.h>
/*
 In a two's complement system, -1 is represented by a binary number with only
 1 bits, like 1111 1111 in an 8-bit word. x-1 is calculated as x+(-1).
 Because all bits in -1 are 1, the rightmost 1-bit will be summed to another 1-bit,
 and result in 0 with a carry of 1. Because all bits in -1 are 1, the carry bit will 
 cause an overflow and get discarded, thus eliminating the rightmost 1-bit in x.

 With this knowledge in hands, we can write a faster version of bitcount, that jumps 
 to the next rightmost 1-bit every iteration, instead of counting out every single bit in the word.
*/
int bitcount(signed x);

int main() {
    //25 has 3 1-bits
    printf("25 has %d 1-bits\n", bitcount(25));
    return 0;
}

int bitcount(signed x) {
    int b;

    for(b = 0; x != 0; x &= (x-1))
        b++;

    return b;
}
