#include <stdint.h>
#include <stdio.h>
uint32_t average(uint32_t a, uint32_t b) { return (a + b) / 2; }

int main() {
  uint32_t a = 3000000000;
  uint32_t b = 3000000000;
  uint32_t sum = average(a, b);
  int c = 6000000000 - 4294967295; /*overflow test*/

  printf("test for result : %d\n", sum);
  printf("overflow result : %d\n", c / 2);
  return 0;
}