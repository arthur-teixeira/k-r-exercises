#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

float toCelsius(int);

int main() {
  int fahr;

  printf("F°\tC°\n");
  for (fahr = UPPER; fahr > LOWER; fahr = fahr - STEP)
    printf("%3d %6.1f\n", fahr, toCelsius(fahr));

  return 0;
}

float toCelsius(int f) {
  return (5.0/9.0)*(f-32);
}