#include <stdio.h>

void main() {
  long nc;

  for (nc = 0; getchar() != EOF; ++nc)
    ;

  printf("%1d\n", nc);
}