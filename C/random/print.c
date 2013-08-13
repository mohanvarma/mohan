#include<stdio.h>
#include<string.h>
int main()
{
    char * str= "aabbbcddddeeef2j3ki";
    int key;
    int count = 1;
    int i = 0;
    key = str[0];
    for(i=1;i<=strlen(str);i++)
    {
	if(key == str[i])
	    count++;
	else
	    {
	    printf("%c%d",key, count);
	    count = 1;
	    }
	key = str[i];

    }
}
