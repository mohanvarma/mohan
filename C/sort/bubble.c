#include<stdio.h>
void bub_sort(int a[], int size)
{
	int i = size;
	int j;
	while(i>0)
	{
		for(j=0; j<i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
		i--;
	}
}	
int main()
{
	int arr[] = {5,6,2,4,1,7,90,10,8,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int index = 0;
	for(index; index<size; index++)
	{
		printf(" %d ", arr[index]);
	}
	printf("\n********\n");

	bub_sort(arr, size);

	for(index = 0; index<size; index++)
	{
		printf(" %d ", arr[index]);
	}
	printf("\n");
	return 0;
}
