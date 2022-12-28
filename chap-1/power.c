#include <stdio.h>

int power(int, int);

int main() {

  for(int i=0; i <10; ++i) 
    printf("%d %d %d\n", i, power(2,i), power(-3, i));

  return 0;
}

int power(int base, int exponent) {
  int result;

  for(result=1; exponent > 0; --exponent)
    result = result * base;

  return result;
}