#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int numerator = 36;
  int denominator = 5;
  int size = 1024;
  char *result = malloc(size);
  char *p = result;

  /* using long long type make sure there has no integer overflow */
  long long n = numerator;
  long long d = denominator;

  /* deal with negtive cases */
  if (n < 0)
    n = -n;
  if (d < 0)
    d = -d;

  bool sign = (float)numerator / denominator >= 0;
  if (!sign)
    *p++ = '-';

  long long remainder = n % d;
  long long division = n / d;

  printf("test : %s\n", p);
  sprintf(p, "%ld", division > 0 ? (long)division : (long)-division);
  printf("test : %s\n", result);
  p = result + strlen(result);
  printf("test : %s\n", p);
  printf("test : %ld\n", strlen(result));

  return 0;
}