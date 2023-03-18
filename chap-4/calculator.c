#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define ALPHA 26
#define SET_VAR '8'
#define GET_VAR '9'

int getop(char[]);
void push(double);
double pop(void);
double top();
void duplicate();
void swap();
void clear();

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

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack overflow\n");
}

double pop() {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack underflow\n");
    return 0.0;
  }
}

double top() {
  if (sp > 0)
    return val[sp - 1];
  else {
    printf("The stack is empty\n");
    return 0.0;
  }
}

void duplicate() {
  if (sp > 0) {
    double prev = val[sp - 1];
    push(prev);
  }
}

void swap() {
  if (sp > 1) {
    double temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;
  }
}

void clear() { sp = 0; }

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if ('A' <= c && c <= 'Z')
    return SET_VAR;
  if ('a' <= c && c <= 'z')
    return GET_VAR;

  i = 0;
  if (c == '-' && !isdigit(s[++i] = c = getch())) {
    ungetch(c);
    c = s[0];
  }

  if (!isdigit(c) && c != '.')
    return c;

  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';

  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("error: Too many characters\n");
  else
    buf[bufp++] = c;
}
