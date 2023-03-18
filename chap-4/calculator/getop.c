#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[]) {
  int i, c;

  static int c_buf;

  if (c_buf == 0)
      c = getch();
  else {
      c = c_buf;
      c_buf = 0;
  }

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if ('A' <= c && c <= 'Z')
    return SET_VAR;
  if ('a' <= c && c <= 'z')
    return GET_VAR;

  i = 0;
  if (c == '-' && !isdigit(s[++i] = c = getch())) {
    c_buf = c;
    c = s[0];
  }

  if (!isdigit(c) && c != '.')
    return c;

  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';

  if (c != EOF)
      c_buf = c;
  return NUMBER;
}
