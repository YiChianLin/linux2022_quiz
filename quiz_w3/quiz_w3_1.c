#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//產生 h~l 之間為 1 的 bitmask
//~0UL 為 11111....11 (64個)
#define GENMASK(h, l) \
    (((~0UL) >> (63 - h)) & ((~0UL) >> (l) << (l)))

//顯示二進位元的方式
char* itobs(int n, char *ps) {
    int size = 8 * sizeof(n);
    int i = size -1;
    while(i+1) {
        ps[i--] = (1 & n) + '0';
        n >>= 1;
    }
    ps[size] = '\0';
    return ps;
}

int main(int argc, char **argv) {
  unsigned int a = 6, b = 4;
  unsigned long n = GENMASK(a, b);
  char s [8 * sizeof(n) + 1];
  printf("%ld = %s\n", n, itobs(n,s));

  printf("test d: %d\n", (~0UL));
  printf("test ld: %ld\n", (~0UL));
  printf("test u: %u\n", (~0UL));
  printf("test lu: %lu\n", (~0UL));
  printf("test d: %d\n", (~0UL)>>2);
  printf("test ld: %ld\n", (~0UL)>>2);
  printf("test u: %u\n", (~0UL)>>2);
  printf("test lu: %lu\n", (~0UL)>>2);

  return 0;
}