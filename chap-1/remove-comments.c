#include <stdio.h>
#define PROGRAM 0
#define COMMENT 1 
#define COMMENT_SINGLE 4 
#define MULTI_COMMENT 5 
#define MULTI_COMMENT_END 6 
void compute_state(int c);
int state = PROGRAM;

int main() {
  int c;
  while((c = getchar()) != EOF) {
    compute_state(c);
  }
  return 0; 
}
void compute_state(int c) {
  if (state == PROGRAM) {
    if (c == '/') {
      state = COMMENT;
      return;
    }
    printf("%c", c);
    return;
  } else if (state == COMMENT) {
    if (c != '/' && c != '*') {
      state = PROGRAM;
      printf("/%c", c);
      return;
    }
    if (c == '/') state = COMMENT_SINGLE; 
    if (c == '*') state = MULTI_COMMENT; 
    return;
  } else if (state == COMMENT_SINGLE) {
    if (c == '\n') {
      state = PROGRAM;
      printf("%c", c);
    }
    return;
  } else if (state == MULTI_COMMENT) {
    if (c == '*') state = MULTI_COMMENT_END;
    return;
  } else if (state == MULTI_COMMENT_END) {
    if (c == '/') state = PROGRAM;
    if (c != '/' && c != '*') state = MULTI_COMMENT;
    return;
  }
}
