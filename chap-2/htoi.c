#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char[]);

int main() {
  printf("%d", htoi("0xfff"));

  return 0;
}

int htoi(char s[]) {
  int i = 0;
  int res = 0;

  if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x'))
    i = 2;

  for(; i < strlen(s); ++i) {
    res = res * 16;

    if(isdigit(s[i]))
      res = res + s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f') 
      res = res + s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
      res = res + s[i] - 'A' + 10;
  }
  return res;
}

