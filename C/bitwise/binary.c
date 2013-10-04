#include<stdio.h>
int main()
{
	int s = -10;
	printf("%x\n",s);
	s = -256;
	printf("%x\n",s);
	s = 0xffffffff;
	printf("%x\n",s);
	printf("%d\n",s);
	return 0;
}
