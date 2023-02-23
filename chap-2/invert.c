#include <stdio.h>

int invert(unsigned int x, int p, int n);

int main() {
  const int result = invert(8, 2, 3);
  printf("result is %d\n", result);
  return 0;
}

int invert(unsigned int x, int p, int n) {
    int bitmask = ~((~0) << n) << p; 
    return x ^ bitmask;
}
