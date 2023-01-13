#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {

  printf("signed char max: %d\n", SCHAR_MAX);
  printf("signed char min: %d\n", SCHAR_MIN);
  printf("unsigned char max: %d\n", UCHAR_MAX);
  
  printf("unsigned short max: %d\n", USHRT_MAX);
  printf("signed short max: %d\n", SHRT_MAX);
  printf("signed short min: %d\n", SHRT_MIN);

  printf("unsigned int max: %d\n", UINT_MAX);
  printf("signed int max: %d\n", INT_MAX);
  printf("signed int min: %d\n", INT_MIN);

  printf("unsigned long max: %ld\n", ULONG_MAX);
  printf("signed long max: %ld\n", LONG_MAX);
  printf("signed long min: %ld\n", LONG_MIN);



  return 0;
}

