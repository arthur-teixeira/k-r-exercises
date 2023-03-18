#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int width);

int main() {
  char s[100] = "";
  int n = 129;
  int width = 5;
  itoa(n, s, width);

  printf("%s\n", s);
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

void itoa(int n, char s[], int width) {
  int i, sign;

  if ((sign = n) > 0)
    n = -n;
  i = 0;

  do {
    s[i++] = '0' - (n % 10);
  } while ((n /= 10) < 0);

  if (sign < 0)
    s[i++] = '-';

  while (i < width)
    s[i++] = ' ';

  s[i] = '\0';
  reverse(s);
}
