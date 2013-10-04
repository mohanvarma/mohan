#include<time.h>

#include<stdio.h>
#include<stdlib.h>
int arr[100000];
int arr2[100000];
long long inversions = 0;
long long inv = 0;
void merge(int arr[], int low, int high, int arr2[]);
void merge_sort(int arr[], int low, int high, int arr2[]);
#define COPY_MERGED(arr2, low, high, arr, k) for(k=low; k<=high; k++) arr[k] = arr2[k];

int main()
{
	clock_t start, end;

	start = clock();

	freopen("IntegerArray.txt", "r" , stdin);
	int count = 0;
	long long int inv = 0;
	while(scanf("%d", &arr[count++])!=EOF  && count<100000)
	{
	}

	end = clock();
	printf("Took %f secs to read\n", 1.0*(end-start)/CLOCKS_PER_SEC);

	printf("%d\n", count);
	printf("%d\n", arr[count-3]);
	printf("%d\n", arr[count-2]);
	printf("%d\n", arr[count-1]);
	int i,j;
	//Counting inversions
	/*
    for(i=0; i<(100000-1); i++)
    {
    for(j=i+1; j<100000; j++)
    {
    if(arr[i] > arr[j])
    inv++;
    }
    }
    printf("Inversions: %lld", inv);
	 */
	start = clock();

	merge_sort(arr, 0, 99999, arr2);

	end = clock();
	printf("Merge took %f secs when aux array used\n", 1.0*(end-start)/CLOCKS_PER_SEC);

	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);
	printf("%d\n", arr[59983]);
	printf("%d\n", arr[count-3]);
	printf("%d\n", arr[count-2]);
	printf("%d\n", arr[count-1]);
	printf("Number of inversions: %lld\n", inversions);
	return 0;
}

//low, high are inclusive.
void merge(int arr[], int low, int high, int arr2[])
{
	//Should not enter here
	if(low==high || low>high)
		return;

	int mid = (low+high)/2;
	int i = low;
	int j = mid+1;
	int k = low;

	while(k<=high)
	{
		if(i<=mid && j<=high)
		{
			if(arr[i] < arr[j])
			{
				arr2[k] = arr[i];
				i++;
				k++;
				continue;
			}
			else
			{
				arr2[k] = arr[j];
				j++;
				k++;
				//Inc inversions by num of remaining elements in 1st half
				inversions+=(mid-i+1);
				continue;
			}
		}

		if(i>mid)
		{
			arr2[k] = arr[j];
			j++;
			k++;
			continue;
		}

		if(j>high)
		{
			arr2[k] = arr[i];
			i++;
			k++;
			continue;
		}
	}

}
//low, high are inclusive.
void merge_sort(int arr[], int low, int high, int arr2[])
{
	int mid;

	if(low==high || low>high)
		return;

	int k=0;
	mid = (low+high)/2;
	merge_sort(arr, low, mid, arr2);
	merge_sort(arr, mid+1, high, arr2);
	merge(arr, low, high, arr2);
	COPY_MERGED(arr2, low, high, arr, k);
}

