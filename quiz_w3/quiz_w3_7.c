#include <stdio.h>
#include <stdint.h>

int ilog32(uint32_t v)
{
    int ret = v > 0;
    int m = (v > 0xFFFFU) << 4;
    v >>= m;
    ret |= m;
    m = (v > 0xFFU) << 3;
    v >>= m;
    ret |= m;
    m = (v > 0xFU) << 2;
    v >>= m;
    ret |= m;
    m = (v > 0x3U) << 1;
    v >>= m;
    ret |= m;
    printf("ret: %d", ret);

    ret += v > 1;
    return ret;
}

int main()
{
    uint32_t b = 31;

    printf("result : %d\n", ilog32(b));    
    return 0;
}