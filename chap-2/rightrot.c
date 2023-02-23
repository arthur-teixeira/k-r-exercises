#include <limits.h>
#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);

int main() {
    printf("result is %d", rightrot(74, 3)); 
    return 0;
}


unsigned int rightrot(unsigned int x, unsigned int n) {
// 0100 1010 is 74
// 0100 1001 is 73
// first get overflowed bits
  size_t s = sizeof(x) * CHAR_BIT;
  unsigned int overflowed = x << (s-n); //0100 0000
  int rest = x >> n; // 0000 1001

  return rest | overflowed;
}

