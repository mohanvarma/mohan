#include<stdio.h>
int main()
{
	long long int i = 0;
	for(i = 1000000; i>=0; i--)
	{
		printf("\r Integer: %d", i);
		//fflush(stdout);
	}
}
