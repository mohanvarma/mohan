#include<stdio.h>
void print_bin(unsigned int a);
int main()
{
    unsigned int a = 20;
    unsigned bit = 0;
    print_bin(a);
    printf("\n");
    //10100

    //Get bit n
    bit = (a&(1<<2))>>2;
    printf("2nd bit %u\n",bit);
    bit = (a&(1<<4))>>4;
    printf("4th bit %u\n",bit);

    // Set bit n
    bit = a|(1<<3);
    print_bin(bit);
    printf("\n");

    // Clear bit n
    bit = a&(~(1<<2));
    print_bin(bit);
    printf("\n");

    // Toggle bit n
    bit = a^(1<<2);
    print_bin(bit);
    printf("\n");
    return 0;
}

void print_bin(unsigned int a)
{
    if(a)
    {
	unsigned int b = 0;
	b = a&1;
	a = a>>1;
	print_bin(a);
	printf("%d", b);
    }
}
