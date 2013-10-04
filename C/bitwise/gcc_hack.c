#include <stdio.h>
int main()
{
    unsigned int a = 8;
    unsigned int b = 10;
    //No of set bits
    printf("%d ", __builtin_popcount(a));
    //No of leading 0 bits
    printf("%d ", __builtin_clz(a));
    //No of trailing 0 bits
    printf("%d", __builtin_ctz(a));
    return 0;
}
