#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void itoa(int n, char s[]);

int main() {
    int n = 12345;
    char s[100] = "";

    itoa(n, s);
    printf("%s\n", s);
    n = -563;
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}


void itoa(int n, char s[]) {
  int static i = 0;

  if (n / 10)
      itoa(n / 10, s);
  else {
      i = 0;
      if (n < 0)
          s[i++] = '-';
  }

  s[i++] = abs(n % 10) + '0';
  s[i] = '\0';
}

