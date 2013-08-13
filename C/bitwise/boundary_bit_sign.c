#include<stdio.h>
#define k 0x7fffffff;

int main()
{
    int a = k;
    a = a+1;
    printf("%x %d",a,a);
    unsigned int b = k;
    b = b+1;
    printf("%x %u",b,b);
}
