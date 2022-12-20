#include <stdio.h>

void main() {
  int celsius;

  int lower = 0;
  int upper = 300;
  int step = 20;

  int fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
}