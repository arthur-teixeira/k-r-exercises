#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORD 11
#define MAXHIST 15

void main() {
  int i, nc, state;
  int len, maxvalue;
  int c, curWordLength;

  int wl[MAXWORD];

  state = OUT;

  i = curWordLength = 0;

  for (i = 0; i < MAXWORD; i++) 
    wl[i] = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (curWordLength > 0) {
        if (curWordLength < MAXWORD)
          ++wl[curWordLength];
      }
      curWordLength = 0;
    } else if (state == OUT) {
      curWordLength = 1;
      state = IN;
    } else {
      ++curWordLength;
    }
  }

  maxvalue = 0;
  for (i = 1; i < MAXWORD; i++)
    if (wl[i] > maxvalue)
      maxvalue = wl[i];
  
  for (i = 1; i < MAXWORD; ++i) {
    printf("%5d - %5d : ", i, wl[i]);

    if(wl[i] > 0) {
      if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
        len = 1;
    } else
      len = 0;

    while (len > 0) {
      putchar('*');
      --len;
    }
    putchar('\n');
  }
}