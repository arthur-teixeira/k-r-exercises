#include <stdio.h>

#define MAX_LINE_SIZE 200
#define LINE_SIZE_BREAKPOINT 80

int get_next_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  char cur_line[MAX_LINE_SIZE];

  for (;;) {
    len = get_next_line(cur_line, MAX_LINE_SIZE);
    if (len == 0) break;
    if (len >= LINE_SIZE_BREAKPOINT) {
      printf("%d characters long: %s\n", len, cur_line);
    } 
  }

  return 0;
}

int get_next_line(char s[], int lim) {
  int c, i;

  i = 0;
  while (i < lim - 1) {
    c = getchar();
    if (c == EOF || c == '\n') break;
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}