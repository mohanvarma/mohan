#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arr[100000];
int arr2[100000];
void merge(int arr[], int low, int high, int arr2[]);
void merge_sort(int arr[], int low, int high, int arr2[]);
#define COPY_MERGED(arr2, low, high, arr, k) for(k=low; k<=high; k++) arr[k] = arr2[k];

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

int binary_search(int key, int low, int high)
{
    if(low>high)
	return -1;
    
    int mid = low+(high-low)/2;

    if(arr[mid] == key)
	return mid;

    if(arr[mid] < key)
	low = mid+1;
    else
	high = mid-1;

    return binary_search(key, low, high);
}

int main() {

    int n,k;
    int i;
    int count = 0;
    scanf("%d", &n);
    scanf("%d", &k);

    for(i=0; i<n; i++)
	scanf("%d", &(arr[i]));

    //NlogN
    merge_sort(arr, 0, n-1, arr2);

    //+ N*logN
    for(i=0; i<n; i++)
    {
	if(binary_search(arr[i]+k, 0, n-1) != -1)
		count++;	    
    }
    
    printf("%d", count);

    return 0;
}

