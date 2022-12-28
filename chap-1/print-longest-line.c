#include <stdio.h>
#define MAXLINE 1000

int get_next_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len, max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = get_next_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)
    printf("%s\n", longest);

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

void copy(char to[], char from[]) {
  int i = 0;

  while(from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
}