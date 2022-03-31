#include<stdio.h>

#define DIVIDE_ROUND_CLOSEST(x, divisor)                       \
    ({                                                         \
        typeof(x) __x = x;                                     \
        typeof(divisor) __d = divisor;                         \
        (((typeof(x)) -1) > 0 || ((typeof(divisor)) -1) > 0 || \
         (((__x) > 0) == ((__d) > 0)))                         \
            ? (((__x) + ((__d) >> 1))) / (__d))                \
            : (((__x) - ((__d) >> 1))) / (__d));               \
    })

int main()
{
    unsigned int a;
    int b;
    printf("result : %d\n", ((typeof(a)) -1) > 0);
    printf("result : %d\n", ((typeof(b)) -1) > 0);
    return 0;
}