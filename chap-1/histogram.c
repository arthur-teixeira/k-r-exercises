#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORD 11
#define MAXHIST 15

void main() {
  int c, curWordLength, i, wordCounter;
  int state = OUT;

  int ndigit[10];

  i = curWordLength = 0;

  for (i = 0; i < 10; i++) 
    ndigit[i] = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      ndigit[wordCounter] = curWordLength;
      curWordLength = 0;
      ++wordCounter;
    } else {
      ++curWordLength;
      state = IN;
    }
  }

  // Compute last word if it is not followed by whitespace
  if (state == IN) {
    ndigit[wordCounter] = curWordLength;
    curWordLength = 0;
    ++wordCounter;
  }

  printf("word sizes =");
  for (i = 0; i < 10; i++)
    printf(" %d", ndigit[i]);
}