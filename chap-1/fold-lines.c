#include <stdio.h>

#define MAXLINE 1000
#define BREAKPOINT 10

#define FOLDED 1
#define NORMAL 0

int get_line(char s[], int lim);
void fold_line(char s[]);

int main() {
  int len;
  char cur_line[MAXLINE];

  for(;;) {
    len = get_line(cur_line, MAXLINE);
    if (len == 0) break;

    fold_line(cur_line);
    printf("%s", cur_line);
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;
 
  i = 0;
  while (i < lim - 1) {
    c = getchar();
    if (c == '\n' || c == EOF) break;

    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void fold_line(char s[]) {
  int last_known_blank;
  int i;
  int state = NORMAL;

  for(i = 0; s[i] != '\0'; ++i) {
    if (s[i] == ' ') 
      last_known_blank = i;
  
   if (i > BREAKPOINT) {
      if (last_known_blank) {
        s[last_known_blank] = '\n';
        i -= last_known_blank;
      }

      last_known_blank = 0;
    }
  }
}
