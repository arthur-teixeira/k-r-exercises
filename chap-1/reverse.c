#include <stdio.h>

#define MAXLINE 100

int get_next_line(char s[], int lim);
void reverse(char to[], char from[]);

int main() {
  int len;
  char cur_line[MAXLINE];
  char reversed[MAXLINE];

  for (;;) {
    len = get_next_line(cur_line, MAXLINE);
    if (len == 0) break;

    reverse(reversed, cur_line);
    printf("reversed %s\n", reversed);
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

void reverse(char to[], char from[]) {
  int count, end, begin;
  count = 0;

  while (from[count] != '\0')
    ++count;

  if (count == 0 || from[count] == '\0')
		to[count] = '\0';

  int k = 0;
  for (--count; count >= 0; --count) {
    to[count] = from[k];
    k++;
  }
}