#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100
#define ALPHA 26

int main() {
  int type;
  double op2;
  char s[MAXOP];
  double var[ALPHA];

  for (int i = 0; i < ALPHA; i++)
    var[i] = 0.0;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case SET_VAR:
      op2 = top();
      var[s[0] - 'A'] = op2;
      break;
    case GET_VAR:
      push(var[s[0] - 'a']);
      break;
    case '?':
      printf("%f", top());
      break;
    case '#':
      duplicate();
      break;
    case '~':
      swap();
      break;
    case '!':
      clear();
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("zero division error\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("zero division error\n");
      break;
    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case '[':
      push(sin(pop()));
      break;
    case ']':
      push(cos(pop()));
      break;
    case '{':
      push(tan(pop()));
    case '}':
      push(exp(pop()));
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unkown command %s\n", s);
      break;
    }
  }

  return 0;
}
