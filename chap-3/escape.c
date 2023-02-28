#include <stdio.h>

void escape(char s[], char t[]);

int main() {
  char t[100] = "";
  char s[50] = "test\n test\t blablabla";
  escape(s, t);
  printf("%s\n", t);
  return 0;
}

void escape(char s[], char t[]) {
  int i, c;

  for (i = 0; s[i] != '\0'; i++) {
    switch (s[i]) {
      case '\t':
        t[i] = '\\';
        t[++i] = 't';
        break;
      case '\n':
        t[i] = '\\';
        t[++i] = 'n';
        break;
      default:
        t[i] = s[i];
    }
  }

  t[++i] = '\0';
}
