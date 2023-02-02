#include <stdio.h>

void squeeze(char s[], char s2[]);

int main() {
  char s1[] = "This is another test";
  char s2[] = "cat";

  squeeze(s1, s2);

  printf("%s", s1);

  return 0;
}

void squeeze(char s[], char s2[]) {
  int i, j, k = 0;

  for (i = j = 0; s[i] != '\0'; i++) {
    int is_match = 0;
    for (k = 0; s2[k] != '\0'; k++)
      if (s[i] == s2[k])
        is_match = 1;

    if (!is_match)
      s[j++] = s[i];
  }

  s[j] = '\0';
}
