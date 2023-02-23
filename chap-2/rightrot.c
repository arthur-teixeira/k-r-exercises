#include <limits.h>
#include <stdio.h>

unsigned char rightrot(unsigned char x, unsigned char n);

int main() {
    printf("result is %d", rightrot(74, 3)); 
    return 0;
}


unsigned char rightrot(unsigned char x, unsigned char n) {
  size_t s = sizeof(x) * CHAR_BIT;
  unsigned int overflowed = x << (s-n); 
  int rest = x >> n; 

  return rest | overflowed;
}

