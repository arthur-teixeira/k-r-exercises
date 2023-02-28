#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 100

void expand(char s1[], char s2[], int n);
int expandable(int a, int b);

int main() {
  char s1[MAX_LINE] = "a-b-d A-Z 0-9";
  char s2[MAX_LINE] = "";

  expand(s1, s2, 0);

  printf("%s\n", s2);
  return 0;
}

void expand(char s1[], char s2[], int n) {
  
  int i, j, prev, cur, next;

  prev = '\0';
  for (i = 0, j = 0; (cur = s1[i]) != '\0'; i++) {
    next = s1[i + 1];
    if (cur == '-' && expandable(prev, next))
      while (++prev < next) 
        s2[j++] = prev;
    else
     s2[j++] = cur;

    prev = cur;
  }

  s2[j] = cur;
}

int expandable(int a, int b) {
  return (isdigit(a) && isdigit(b) ||
          (isalpha(a) && isupper(a) && isalpha(b) && isupper(b)) ||
          (isalpha(a) && islower(a) && isalpha(b) && islower(b)));
}

