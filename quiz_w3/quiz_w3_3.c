#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t rev8(uint8_t x) {
  x = (x >> 4) | (x << 4);
  x = ((x & 0xCC) >> 2) | ((x & 0x33) << 2);
  x = ((x & 0xAA) >> 1) | ((x & 0x55) << 1);
  return x;
}

int main(int argc, char **argv) {

  uint8_t n = 0x35;
  printf("origin : 0x%x value : %d\n", n, n);
  n = rev8(n);
  printf("after rev : 0x%x value : %d\n", n, n);
  return 0;
}