#include<stdio.h>
int main()
{
	int a = 3;
	int b = 5;
	printf("Before: %d %d\n",a,b);
	b = a + b - (a = b);
	printf("Before: %d %d\n",a,b);
}
