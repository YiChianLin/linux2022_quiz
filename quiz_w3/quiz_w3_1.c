#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define GENMASK(h, l) (((~0UL) >> (63 - h)) & ((~0UL) >> (l) << (l)))

char *itobs(int n, char *ps) {
  int size = 8 * sizeof(n);
  int i = size - 1;
  while (i + 1) {
    ps[i--] = (1 & n) + '0';
    n >>= 1;
  }
  ps[size] = '\0';
  return ps;
}

int main(int argc, char **argv) {
  unsigned int a = 6, b = 4;
  unsigned long n = GENMASK(a, b);
  char s[8 * sizeof(n) + 1];
  printf("%ld = %s\n", n, itobs(n, s));
  return 0;
}
