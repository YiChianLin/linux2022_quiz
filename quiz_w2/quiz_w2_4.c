#include <stdint.h>
#include <stdio.h>

int main() {
  uint8_t a = 1;
  uint8_t b = -a;

  printf("result : %x\n", a);
  printf("result : %x\n", b);
  printf("result : %x\n", a & b);
  printf("result : %d\n", a);
  printf("result : %d\n", b);
  printf("result : %d\n", a & b);
  return 0;
}