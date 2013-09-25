#include<stdio.h>
#include<stdlib.h>

#define PRINT_ALL(arr, n, i) for(i=0; i<n; i++) printf("%d ",arr[i]); printf("\n")

void bubble_sort(int arr[], int size)
{
	int i, j;
	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size; j++)
		{
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//low, high are inclusive.
void merge(int arr[], int low, int high)
{
	//Should not enter here
	if(low==high || low>high)
		return;

	int mid = (low+high)/2;
	int i = low;
	int j = mid+1;
	int k = low;
	int lmt1 = (mid-low)+1;
	int lmt2 = (high-(mid+1))+1;
	int * tmp1 = (int*)malloc(sizeof(int)*lmt1);
	int * tmp2 = (int*)malloc(sizeof(int)*lmt2);
	int p;
	for(p=0; p<lmt1; p++)
	{
		tmp1[p] = arr[low+p];
	}

	for(p=0; p<lmt2; p++)
	{
		tmp2[p] = arr[mid+1+p];
	}

	while(k<=high)
	{
		if(i<=mid && j<=high)
		{
			if(tmp1[i-low] < tmp2[j-(mid+1)])
			{
				arr[k] = tmp1[i-low];
				i++;
				k++;
				continue;
			}	
			else
			{
				arr[k] = tmp2[j-(mid+1)];
				j++;
				k++;
				continue;
			}
		}

		if(i>mid)
		{
			arr[k] = tmp2[j-(mid+1)];
			j++;
			k++;
			continue;
		}

		if(j>high)
		{
			arr[k] = tmp1[i-low];
			i++;
			k++;
			continue;
		}
	}

	free(tmp1);
	free(tmp2);
}
//low, high are inclusive.
void merge_sort(int arr[], int low, int high)
{
	int mid;

	if(low==high || low>high)
		return;

	mid = (low+high)/2;
	merge_sort(arr, low, mid);
	merge_sort(arr, mid+1, high);
	merge(arr, low, high);
}

int main()
{
	int arr[10] = {8, 8, 1, 3, 9, 1, 79, 65, 34, 26};
	//int arr[4] = {8, 1, 9, 2};

	int i,j,k;
	//bubble_sort(arr, 10);
	PRINT_ALL(arr, 10, k);
	merge_sort(arr, 0, 9);
	PRINT_ALL(arr, 10, k);
	/*
	for(i=0; i<(10-1); i++)
	{
		for(j=0; j+1<(10-i); j++)
		{
			if(arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;	
			}
		}
		PRINT_ALL(arr, 10, k);
	}
	PRINT_ALL(arr, 10, k);
	*/
	return 0;
}

