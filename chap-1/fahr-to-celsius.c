#include <stdio.h>

void main() {
  float celsius;

  float lower = 0;
  float upper = 300;
  float step = 20;

  float fahr = lower;

  printf("F°\tC°\n");
  while (fahr <= upper) {
    celsius = (fahr-32) * (5.0/9.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}