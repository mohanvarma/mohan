#include<stdio.h>
int main()
{
	int a = 0;
	if(a)
		goto Error;
Error:
	printf("FallThrough\n");
	return;
}
