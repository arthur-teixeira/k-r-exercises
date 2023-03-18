#include <stdio.h>
#include <string.h>
#include "getch.h"

int b = 0;

int getch() { 
    if (b == 0) 
        return getchar();
    else {
        int c = b;
        b = 0;
        return c;
    }
}

void ungetch(int c) {
  if (b != 0)
    printf("error: Too many characters\n");
  else
      b = c;
}

void ungets(char s[]) {
    for(int i = strlen(s); i >= 0; --i)
        ungetch(s[i]);
}
