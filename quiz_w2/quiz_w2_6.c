#include <stdio.h>
#define ALIGNOF(t)                                                             \
  ((char *)(&((struct {                                                        \
               char c;                                                         \
               t _h;                                                           \
             } *)0)                                                            \
                 ->_h) -                                                       \
   (char *)0)

int main() {

  printf("byte of int : %ld\n", ALIGNOF(short));
  return 0;
}
