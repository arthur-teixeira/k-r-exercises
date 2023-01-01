#include <stdio.h>

#define TABSTOP 8
#define ENTAB 1
#define NORMAL 0

int main() {
  int c, state;
  int col, base_col;

  while((c = getchar()) != EOF) {

    if (state == NORMAL) {
      if(c == ' ' || c == '\t') {
        base_col = col;
        state = ENTAB;
      } else {
        putchar(c);
      }
    } else {
      if (c == '\n') {
        state = NORMAL;
        putchar(c);
      } else if (c != ' ' && c != '\t') {
        state = NORMAL;

        // print maximum tabs until base_col is reached
        while ((base_col + (TABSTOP-base_col % TABSTOP)) <= col) {
          base_col += (TABSTOP-base_col % TABSTOP);
          putchar('\t');
        }

        //print remaining spaces needed to reach TABSTOP
        while ((base_col + 1) <= col) {
          base_col++;
          putchar(' ');
        }

        putchar(c);
      }
    }

    if (c == '\t')
      col += (TABSTOP - col % TABSTOP);
    else if (c == '\n')
      col = 0;
    else 
      ++col;
  }



  return 0;
}