#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

uint64_t gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v) return u | v;
    int u_ctz = __builtin_ctz(u);
    int v_ctz = __builtin_ctz(v);
    int shift = u_ctz < v_ctz ? u_ctz : v_ctz;

    u >>= u_ctz;
    v >>= v_ctz;
    
    do {
        v >>= __builtin_ctz(v);
        
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

int main() {
  uint64_t a = 48;
  uint64_t b = 72;
  int result = 0;
  result = gcd64(a, b);
  printf("result : %d\n", result);
  return 0;
}