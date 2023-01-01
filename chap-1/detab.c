#include <stdio.h>

#define TABSTOP 8


int main() {
  int c;
  int counter = 0;

  while((c = getchar()) != EOF) {
    if (c == '\t') {
      for(; counter < TABSTOP; ++counter) {
        putchar(' ');
      }
    } else {
      putchar(c);
      ++counter;
    }

    counter = counter % TABSTOP;
  }

  return 0;
}