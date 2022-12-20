#include <stdio.h>

void main() {
  float celsius;

  float lower = 0;
  float upper = 300;
  float step = 20;

  float fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}