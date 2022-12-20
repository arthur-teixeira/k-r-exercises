#include <stdio.h>

void main() {
  float fahr;

  float lower = 0;
  float upper = 100;
  float step = 10;

  float celsius = lower;

  printf("%6s\t%3s\n", "Celsius", "Fahrenheit");
  while (celsius <= upper) {
    fahr = (celsius * (9.0/5.0)) + 32;
    printf("%7.1f\t%3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

}