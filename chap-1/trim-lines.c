#include <stdio.h>

#define MAX_LINE_SIZE 200

int get_trimmed_line(char line[], int maxline);

int main() {
  int len;
  char cur_line[MAX_LINE_SIZE];

  for (;;) {
    len = get_trimmed_line(cur_line, MAX_LINE_SIZE);
    if (len == 0) break;

    printf("%s\n", cur_line);
  }

  return 0;
}

int get_trimmed_line(char s[], int lim) {
  int c, i, last_non_blank;

  last_non_blank = -1;
  i = 0;
  while (i < lim - 1) {
    c = getchar();
    if (c == EOF || c == '\n') break;
    
    if (c != ' ' && c != '\t') {
      last_non_blank = i;
    }
    
    s[i] = c;
    ++i;    
  }

  s[last_non_blank+1] = '\0';

  return last_non_blank + 1;
}