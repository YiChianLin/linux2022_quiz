#include <stdio.h>
static inline unsigned long fls(unsigned long word)
{
    int num = 64 - 1;
        
    if (!(word & (~0ul << 32))) {
        num -= 32;
        word <<= 32;
    }
    if (!(word & (~0ul << (64 - 16)))) {
        num -= 16;
        word <<= 16;
    }
    if (!(word & (~0ul << (64 - 8)))) {
        num -= 8;
        word <<= 8;
    }
    if (!(word & (~0ul << (64 - 4)))) {
        num -= 4;
        word <<= 4;
    }   
    if (!(word & (~0ul << (64 - 2)))) {
        num -= 2;
        word <<= 2;
    }
    printf("%lx\n", word);
    if (!(word & (~0ul << (64 - 1)))) 
        num -= 1;
    return num;
} 

unsigned long i_sqrt(unsigned long x)
{
    unsigned long b, m, y = 0;

    if (x <= 1)
        return x;
    int i = 0;
    m = 1UL << (fls(x) & ~1UL);
    while (m) {
        b = y + m;
        printf("b : %d %ld\n", i, b);
        y >>= 1;
        printf("y : %d %ld\n", i, y);

        if (x >= b) {
            x -= b;
            y += m;
        }
        m >>= 2;
        printf("m : %d %ld\n", i, m);

        i++;
    }

    return y;
}

int main()
{
    int a = 4;
    printf("%ld\n", i_sqrt(a));
    return 0;
}