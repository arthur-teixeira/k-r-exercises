#include <ctype.h>
#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  int test = 796;
  char s[10] = "";

  itob(test, s, 16);
  printf("%s\n", s);

  return 0;
}

void itob(int n, char s[], int b) {
  int i, sign;

  if ((sign = n) > 0)
    n = -n;
  i = 0;

  do {
    if (!isdigit('0' - (n % b)))
      s[i++] = 'A' - (n % b) - 10;
    else
      s[i++] = '0' - (n % b);
  } while ((n /= b) < 0);

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
