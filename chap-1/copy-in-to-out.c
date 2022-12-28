#include <stdio.h>

//Write a program that copies its input to its output, replacing multiple blanks with a single blank

// Finite State Machine
// if char is blank: getchar until it is not blank, print blank
// else: print char

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') { 
      while ((c = getchar()) == ' ')
        ;
      putchar(' ');
      if (c == EOF) 
        break;
    }
    putchar(c);
  }   

  return 0;
}