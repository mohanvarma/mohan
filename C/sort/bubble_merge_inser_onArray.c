#include <stdio.h>
void print_arr(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubble_sort(int arr[], int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size; j++)
		{
			if(arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insert_sort(int arr[], int size)
{
	int i,j;
	for(i=1; i<size; i++)
	{
		j = i;
		//int key = arr[j];
		while(j>=1 && (arr[j-1]>arr[j]))
		{
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
		//arr[j] = key;
	}
}

void insert_sort2(int arr[], int size)
{
	int i,j;
	for(i=1; i<size; i++)
	{
		j = i;
		int key = arr[j];
		while(j>=1 && (arr[j-1]>key))
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = key;
	}
}

void merge_sort(int arr[], int size, int lower, int upper)
{
	if(lower < upper)
		return;

	if(lower == upper)
		return;

	int middle = (lower+uppder)/2;

	merge_sort(arr[], size, lower, middle);
	merge_sort(arr[], size, middle+1, upper);

	int i;
	for(i=0; i<=middle; i++)
	{
		
	}

}


int main()
{
	int arr[] = {-17,9,89,108,2,7,18,91,27,45,34,26,78,90,0,1};
	int size = sizeof(arr)/sizeof(int);
	print_arr(arr, size);
	//Sort
	//bubble_sort(arr,size);
	insert_sort2(arr,size);
	//sort(arr, size);
	print_arr(arr, size);
	return 0;
}
