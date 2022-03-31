#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct foo; /* */
  
struct fd {
    struct foo *foo;
    unsigned int flags;
};

enum {
    FOO_DEFAULT = 0,
    FOO_ACTION,                           
    FOO_UNLOCK,
} FOO_FLAGS;

static inline struct fd to_fd(unsigned long v)
{
    return (struct fd){(struct foo *)(v & ~3), v & 3};
}

int main(int argc, char **argv) {
    long long a = 5;
    struct fd test = to_fd(a);

    printf("alignment : %p %p\n", &test.foo, &test.flags);
    /* alignment : 0x7fff11a83dd0 0x7fff11a83dd8 */
    return 0;
}