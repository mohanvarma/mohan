/*
 * Program to find if a given number has atleast 2 consecutive 1s.
 * If a number has 2 consecutive ones, anding with it's left rotate value
 * gives a non zero result.
 * xxxx11xxxx -> << 1 -> xxx11xxxx0
 * Same technic can be used to find 3 consecutive, 4 consecutive, longest sequence of 1s...
 */

#include<stdio.h>
void print_binary(int x)
{
    if(!x)
    {
	return;
    }
    print_binary(x>>1);
    printf("%d", x&1);
}

int main()
{
    unsigned int i;
    int count = 0;

    for(i=0; i<32; i++)
    {
	if(i & (i<<1))
	{
	    printf("%x:",i);
	    print_binary(i);
	    printf("\n");
	    count++;
	}
    }

    printf("No. of digits with at least 2 consecutive ones:%d\n", count);
    return 0;
}
