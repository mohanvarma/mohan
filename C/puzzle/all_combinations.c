#include<stdio.h>
#include<string.h>
void print_combinations(const char *string)
{
    int i, j, k;
    int len = strlen(string);

    for (i = 0; i < len - 2; i++)
    {
        for (j = i + 1; j < len - 1; j++)
        {
            for (k = j + 1; k < len; k++)
                printf("%c%c%c\n", string[i], string[j], string[k]);
        }
    }
}

int main()
{
	print_combinations("MOHAN");
	return 0;
}

