#include<stdio.h>
#include<math.h>
void print_set(int set[], int len, int i)
{
    //If bit position has 1, print that number
    int j;
    printf("{");
    for(j=0; j<len; j++)
    {
        if((i&(1<<j)))
        {
            printf("%d,", set[j]);
        }
    }
    if(i)
        printf("\b}\n");
    else
        printf("}\n");
}

int main()
{
    int set[] = {10,20,30,40,50,60};
    int len = sizeof(set)/sizeof(set[0]);
    int i=0;

    while(i<pow(2,len))
    {
        print_set(set, len, i);
        i++;
    }

    return 0;
}
