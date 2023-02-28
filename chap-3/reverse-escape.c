#include <stdio.h>

void reverse_escape(char s[], char t[]);

int main() {
  char t[100] = "";
  char s[50] = "test\\n test\\t blablabla";
  reverse_escape(s, t);
  printf("%s\n", t);
  return 0;
}

void reverse_escape(char s[], char t[]) {
  int i, c;

  for (i = 0; s[i] != '\0'; i++) {
    switch (s[i]) {
      case '\\':
        if (s[i+1] == 'n') {
          t[i] = '\n';
          ++i;
        } else if (s[i+1] == 't') {
          t[i] = '\t';
          ++i;
        } else
         t[i] = s[i];
        break;
      default:
        t[i] = s[i];
    }
  }

  t[++i] = '\0';
}
