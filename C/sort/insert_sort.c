#include<stdio.h>
void swap(int*a, int*b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int arr[], int size)
{
	int pos = 0;
	for(pos = 1; pos<size; pos++)
	{
		int i,j;
		for(i = 1; i<size; i++)
		{
			j=i;
			int key;
			key = arr[j];
			while((j>0) && arr[j] > arr[j-1])
			{
				//swap(&arr[j], &arr[j-1]);

				//int tmp;
				//tmp = arr[j];
				arr[j] = arr[j-1];
				//arr[j-1] = tmp;
				j = j-1;
			}
			arr[j] = key; 
		}
	}
}

int main()
{
	int arr[10] = {10,8,2,4,6,7,1,9,9,3};
	sort(arr, 10);
	int id = 0;
	for(id; id<10; id++)
	{
		printf("%d ",arr[id]);
	}
	printf("\n");	
	return 0;
}
