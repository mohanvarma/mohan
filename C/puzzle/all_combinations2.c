#include<stdio.h>
#include<malloc.h>
#include<string.h>
char c[] = {'a','b','c','d'};
int CHARS = 4;
int count = 1;
int LEN = 2;
void generate_repeat(char a[], int start, int len);
void generate_no_repeat(char a[], int start, int len);
void generate_permutation(char a[], int start, int len);

int main()
{
        char* a = malloc(4*sizeof(char));
        a[CHARS]=0;
        //generate_repeat(a,0,CHARS);
        //generate_permutation(a,0,CHARS);
        generate_no_repeat(a,0,CHARS);
        return 0;
}

void generate_repeat(char a[], int start, int len)
{
        int i=0;
        if(len==LEN)
        {
                printf("%d %s \n",count++, a);
                //count++;
                return;
        }
        for(i=0; i<CHARS; i++)
        {
                a[start] = c[i];
                generate_repeat(a, start+1, len-1);
        }
}

void generate_no_repeat(char a[], int start, int len)
{
        int i=0;
        if(len==LEN)
        {
                printf("%d %s \n",count++, a);
                //count++;
                return;
        }
        for(i=0; i<CHARS; i++)
        {
                if(!strchr(a,c[i]))
                {
                        a[start] = c[i];
                        generate_no_repeat(a, start+1, len-1);
                        //a[start] = 0;
                }
        }
}

void generate_permutation(char a[], int start, int len)
{
        int i=0;
        if(len==0)
        {
                printf("%d %s \n",count++, a);
                //count++;
                return;
        }
        for(i=0; i<CHARS; i++)
        {
                int flag = 0;
                int j = 0;
                for(j=0; j<start; j++)
                {
                        if(a[j] == c[i])
                        {
                                flag = 1;
                                break;
                        }
                }
                if(flag)
                        continue;
                else
                {
                        a[start] = c[i];
                        generate_permutation(a, start+1, len-1);
                }
        }
}
