#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int strindex(char s[], char t[]);

int main() {
  char s[MAXLINE] = "if i could i would";
  char t[MAXLINE] = "ould";
  printf("%d\n", strindex(s, t));

  return 1;
}

int strindex(char s[], char t[]) {
  int i, j, k;

  for (i = strlen(s); i >= 0; i--) {
    for (j = i, k = strlen(t); k >= 0 && s[j] == t[k]; j--, k--)
      ;
    if (k < i)
      return i - strlen(t);
  }

  return -1;
}
