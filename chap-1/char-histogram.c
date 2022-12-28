#include <stdio.h>

#define ASCII_OFFSET 33
#define ASCII_END 126

int main() {
  int len_freq[94];
  int height;
  int c, i, k;

  height = 0;

  for (i = 0; i < 93; i++) 
    len_freq[i] = 0;

  while((c = getchar()) != EOF) {
    if (ASCII_OFFSET <= c && c <= ASCII_END) {
      ++len_freq[c-ASCII_OFFSET];
      if (len_freq[c-ASCII_OFFSET] >= height)
        height = len_freq[c-ASCII_OFFSET];
    }
  }

  for(i = height; i > 0; --i) {
    printf("%4d|", i);
    for (k = 0; k <= ASCII_END - ASCII_OFFSET; ++k) {
      if(len_freq[k] >= i) 
        putchar('#');
      else
        putchar(' ');
    }
    putchar('\n');
  }

  printf("    +");
  for(i = ASCII_OFFSET; i <= ASCII_END; ++i) 
    putchar('-');
  printf("\n     ");

  for(i = ASCII_OFFSET; i <= ASCII_END; ++i)
    putchar(i);

  putchar('\n');

  return 0;
}