#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i,j;
	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size; j++)
		{
			printf("%d %d", arr[i], arr[j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
