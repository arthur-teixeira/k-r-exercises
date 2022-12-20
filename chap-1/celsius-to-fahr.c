#include <stdio.h>

void main() {
  int celsius;

  printf("%6s\t%3s\n", "Celsius", "Fahrenheit");
  for (celsius=100; celsius > 0; celsius=celsius-10)
    printf("%3d %6.1f\n", celsius, (celsius * (9.0/5.0)) + 32);

}