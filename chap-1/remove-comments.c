#include <stdio.h>

#define PROGRAM 0 
#define COMMENT 1 // Program - Comment
#define COMMENT_SINGLE 4 // Comment (simple)
#define MULTI_COMMENT 5 // Comment (multiple lines)
#define MULTI_COMMENT_END 6 // Comment (multiple lines) - Program

void compute_state(int c);

int state = PROGRAM;
/*askdjhaksdjhaskjdh*/
int main() {
  int c;

  while((c = getchar()) != EOF) {
    compute_state(c);
  }

  return 0; //removes this one too
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

    if (c == '/') state = COMMENT_SINGLE; // test
    if (c == '*') state = MULTI_COMMENT; // test 2
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