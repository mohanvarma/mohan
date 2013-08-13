#include<stdio.h>
void print_bin(int a)
{
	if(a)
		print_bin(a>>1);
	if(a)
	printf("%d", a&1);
}

int mirror(int a)
{
	int k = 0;
	while(a)
	{
		int tmp = a&1;
		k = k|tmp;
		if(a != 1)
			k = k << 1;
		a = a>>1;
	}
	return k;
}

int main()
{
	printf("Enter:");
	int a;
	scanf("%d", &a);
	int count = 0;
	print_bin(a);
	int tmp = mirror(a);
	printf("X");
	print_bin(tmp);
	while(a)
	{
		int k = a&1;
		a = a>>1;
		if(k)
			count++;
	}
	printf("\nCount is:%d", count);
}
