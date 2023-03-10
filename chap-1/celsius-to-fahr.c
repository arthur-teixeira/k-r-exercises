#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP  10

float toFahrenheit(int);

int main() {
  int celsius;

  printf("%6s\t%3s\n", "Celsius", "Fahrenheit");
  for (celsius= UPPER; celsius > LOWER; celsius = celsius - STEP)
    printf("%3d %6.1f\n", celsius, toFahrenheit(celsius));

  return 0;
}

float toFahrenheit(int c) {
  return (c * (9.0/5.0)) + 32;
}