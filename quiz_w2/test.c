#include <stdio.h>
int B = 2;
void func(int **p){*p = &B;}
int add(int a, int b);
#define ALIGNOF(t) \
    ((char *)(&(   (struct { char c; t _h; }*) 0)->_h) - (char *)0)

int main(){
    int a = 21;
    int b = 43;
    int sum = 0;
    char a[][3] = {"a", "bc", "ddd"};

    //sum = add(a, b);
    sum = (a >> 1) + (b >> 1) + ( (a & b) & 1); 

    printf("test for sum : %d\n", sum);
    return 0;
}

int add(int a, int b) {
    if (b == 0) return a;
    int sum = a ^ b; /* 相加但不進位 */
    printf("test for sum in fun : %d\n", sum);
    int carry = (a & b) << 1; /* 進位但不相加 */
    printf("test for carry : %d\n", sum);

    return add(sum, carry);
}
