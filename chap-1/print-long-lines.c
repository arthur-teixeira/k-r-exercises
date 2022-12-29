#include <stdio.h>

#define MAX_LINE_SIZE 200
#define MAX_LINES 10

int get_next_line(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len, big_line_count;
  char big_lines[MAX_LINES][MAX_LINE_SIZE];
  char cur_line[MAX_LINE_SIZE];

  big_line_count = 0;
  for (;;) {
    len = get_next_line(cur_line, MAX_LINE_SIZE);
    if (len == 0) break;
    if (len >= 80) {
      copy(big_lines[big_line_count], cur_line);
      ++big_line_count;
    } 
  }

  for(int i =0; i < big_line_count; ++i)
    printf("%d %s\n", i, big_lines[i]);

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