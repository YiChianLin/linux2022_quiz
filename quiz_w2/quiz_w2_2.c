#include <stdint.h>
#include <stdio.h>

uint32_t max(uint32_t a, uint32_t b) { return b ^ ((a ^ b) & -(a > b)); }

int main() {
  uint32_t a = 25;
  uint32_t b = 5;
  uint32_t c = 5;
  uint32_t d = 25;
  uint32_t max_num = max(a, b);

  printf("test for result : %d\n", max_num);
  // printf("test for result : %d\n", -(c < d));

  return 0;
}