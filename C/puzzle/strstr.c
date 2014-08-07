/*
The strstr() function finds the first occurrence of the substring
       needle in the string haystack.  The terminating null bytes ('\0') are
       not compared.
 */
 // char *strcasestr(const char *haystack, const char *needle);
 //

#include<stdio.h>
#include<string.h>
char * strstr_custom(const char* haystack, const char* needle);

int main()
{
	char *ch = strstr_custom("mohanvarma", "varma");
	if(!ch)
	{
		printf("NULL\n");
	}
	else
	{
		printf(ch);
		printf("\n");
	}
	return 0;
}


char * strstr_custom(const char* haystack, const char* needle)
{
	if(!haystack || !needle)
		return NULL;

	// find the first occurence of needle
	int haystack_len = strlen(haystack);
	int needle_len = strlen(needle);

	int i;
	for(i=0; i<haystack_len; i++)
	{
		if(haystack[i] == needle[0])
		{
			int j;
			int k = i;
			int flag = 0;
			for(j=1; j<needle_len && k<haystack_len; j++)
			{
				if(haystack[++k] == needle[j])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if(flag == 0)
			{
				continue;
			}
			else
			{
				return &(haystack[i]);
			}
		}
	}
	return NULL;

}

