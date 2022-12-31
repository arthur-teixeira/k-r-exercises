#include <stdio.h>

#define MAXLINE 100

int get_next_line(char s[], int lim);
void reverse(char s[]);

int main() {
  int len;
  char cur_line[MAXLINE];

  for (;;) {
    len = get_next_line(cur_line, MAXLINE);
    if (len == 0) break;

    reverse(cur_line);
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

void reverse(char s[]) {
  char temp[MAXLINE];

  int count, end, begin;
  count = 0;

  while (s[count] != '\0')
    ++count;

  if (count == 0 || s[count] == '\0')
		temp[count] = '\0';

  int k = 0;
  for (--count; count >= 0; --count) {
    temp[count] = s[k];
    k++;
  }

   printf("reversed %s\n", temp);
}