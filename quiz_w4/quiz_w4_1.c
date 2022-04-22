#include <stdio.h>
#include <stdint.h>

/*取 log2 並取最接近整數(ceil) */
int ceil_log2(uint32_t x)
{
    uint32_t r, shift;

    x--;
    r = (x > 0xFFFF) << 4;                                                                                                                                    
    x >>= r;
    shift = (x > 0xFF) << 3;
    x >>= shift;
    r |= shift;
    shift = (x > 0xF) << 2;
    x >>= shift;
    r |= shift;
    shift = (x > 0x3) << 1;
    x >>= shift;
    return (r | shift | x >> 1) + 1;  /* EXP1 */
}

int main()
{   
    uint32_t x = 64;
    printf("test x(%d) %d\n", x, ceil_log2(x));
    return 0;
}