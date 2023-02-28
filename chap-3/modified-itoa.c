#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  signed char test = -128;
  char s[10] = "";

  itoa(test, s);
  printf("%s\n", s);

  return 0;
}

// The original function won't work because the positive number range is one less than the negative number range in two's complement,
// like -128 to 127. Because of this, the way the function treated negative numbers (inverting the sign) would not convert -128 to 128.
// To solve this, we can do the opposite: convert positive numbers to negative numbers.

void itoa(int n, char s[]) {

  int i, sign;

  if ((sign = n) > 0)
    n = -n;
  i = 0;

  do {
    s[i++] = '0' - (n % 10);
  } while ((n /= 10) < 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int length = strlen(s);
  int c, i, j;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
