#include <stdio.h>
#include <string.h>

int abs(int n)
{
	if(n<0)
		return (-1*n);
	else
		return n;
}

int is_valid(int n)
{
	int num = abs(n);
	char str[10] = {0}; 
	snprintf(str, 10, "%d", num);
	int str_len = strlen(str);
	int is_odd = ((str_len%2==0) ? 0:1 );
	if((str_len<3) || (!is_odd))
	{
		printf("Integer: %d - Not possible to get middle 3 digits\n", n);
		return 0;
	}

	//Now, we have a string, strip the digits and print the middle 3 - string.
	int startIndex = (str_len-3)/2;
	*(str+startIndex+3) = 0;
	printf("Integer: %d - Middle 3 digits are %s\n", n, str+startIndex);
	return 1;
}

int main()
{
	int input_arr[] = {123, 12345, 1234567, 987654321, 10001, -10001, -123, -100, 100, -12345, 1, 2, -1, -10, 2002, -2002, 0};

	int size = sizeof(input_arr)/sizeof(int);

	int index = 0;
	for(index = 0; index<size; index++)
	{
		/*
		if(is_valid(input_arr[index]))
			print_middle_3(input_arr[index]);
		*/
		is_valid(input_arr[index]);
	}
	return 0;
}
