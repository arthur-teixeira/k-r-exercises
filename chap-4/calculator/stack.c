#include <stdio.h>
#include "stack.h"

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

