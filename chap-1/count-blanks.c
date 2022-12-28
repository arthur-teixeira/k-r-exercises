#include <stdio.h>

int main() {
  long blanks = 0;
  long tabs = 0;
  long newLines = 0;

  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++newLines;
    else if (c == '\t')
      ++tabs;
    else if (c == ' ')
      ++blanks;
  }

  printf("%1d blanks\n", blanks);
  printf("%1d tabs\n", tabs);
  printf("%1d newLines\n", newLines);

  return 0;
}