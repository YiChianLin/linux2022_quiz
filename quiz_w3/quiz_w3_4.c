#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define _foreach_no_nullval(i, p, arr) \
    assert((i) >= sizeof(arr) / sizeof(arr[0]) || (p))

#define foreach_int(i, ...)                                            \
    for (unsigned _foreach_i = (((i) = ((int[]){__VA_ARGS__})[0]), 0); \
         _foreach_i < sizeof((int[]){__VA_ARGS__}) / sizeof(int);      \
         (i) = ((int[]){__VA_ARGS__, 0})[++_foreach_i])

#define foreach_ptr(i, ...)                                                 \
    for (unsigned _foreach_i =                                              \
             (((i) = (void *) ((typeof(i)[]){__VA_ARGS__})[0]), 0); \
         (i); (i) = (void *) ((typeof(i)[]){__VA_ARGS__,            \
                                                    NULL})[++_foreach_i],   \
                  _foreach_no_nullval(_foreach_i, i,                        \
                                      ((const void *[]){__VA_ARGS__})))

int main(int argc, char **argv) {

  int i;
  foreach_int(i, 0, -1, 100, 0, -99) {
      printf("i is %i\n", i); 
  }
  const char *p;
  foreach_ptr(p, "Hello", "world") {
      printf("p is %s\n", p);
  }

  printf("test array element : %d\n", (int[]){0 ,100, -1, 0}[1]); /* 100 */
  unsigned _foreach_i = (((i) = ((int[]){0 ,100, -1})[1]), 2);
  printf("%u\n",_foreach_i); /* 2 , 不受 i 影響 */
  const char *test;
  ((test) = (void *) ((typeof(test)[]){"Hello", "world"})[0]);
  printf("%s\n",test);
  return 0;
}