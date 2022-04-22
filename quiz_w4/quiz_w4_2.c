#define BITS_PER_BYTE 8

/* 此 micro 的用意在於不同的電腦系統中 long 的位元長度不同 64/32 */
#define BITS_PER_LONG (sizeof(unsigned long) * BITS_PER_BYTE) 

#include <stddef.h>
#include <stdio.h>

/** 
 * find first set
 * ex: 15 = 1111
 * ffs(15) = 1 
*/
static inline size_t ffs(unsigned long x)
{
    if (x == 0)
        return 0;

    size_t o = 1;
    unsigned long t = ~0UL;       /* 111...11 bitmask */
    size_t shift = BITS_PER_LONG; /* 64 */

    shift >>= 1;
    t >>= shift; /* 一半的 bitmask */

    /* 迴圈對半檢查方法 */
    while (shift) {
        if ((x & t) == 0) { /* EXP2 bitmask 對消*/
            x >>= shift;
            o += shift; /* EXP3 把結果存下來 */
        }

        shift >>= 1;
        t >>= shift;
    }

    return o;
}

int main()
{
    unsigned long x = 64;
    printf("result : %ld\n", ffs(x));
    printf("result : %ld\n", __builtin_ffsl(x));

    return 0;
}