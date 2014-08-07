#include<stdio.h>
void q_sort_algs(int arr[], int low, int high);
// Quick sort can be used for duplicate elements as well, but performance could be O(n^2) for some calls
// as partition sends all equal elements to 1 side only
// 3 way sort can be used in those situations
void q_sort_3way_algs(int arr[], int low, int high);
int main()
{
	int arr[] = {144, 99, 95, 76, 183, 37, 121, 52, 186, 164, 153, 14, 58, 128, 116, 35, 77, 100, 123, 171, 199, 79, 54, 98, 180, 23, 151, 155, 187, 159, 97, 70, 189, 142, 140, 101, 150, 176, 27, 71, 56, 12, 107, 175, 173, 163, 82, 44, 45, 136, 80, 184, 3, 125, 111, 129, 154, 49, 138, 2, 96, 131, 26, 145, 93, 81, 68, 88, 33, 178, 170, 19, 66, 127, 51, 133, 21, 147, 39, 160, 43, 157, 185, 42, 156, 112, 65, 50, 64, 94, 109, 146, 9, 122, 31, 126, 188, 177, 87, 91, 38, 143, 102, 57, 179, 40, 198, 62, 34, 75, 78, 193, 83, 115, 172, 166, 74, 61, 191, 53, 13, 85, 174, 118, 195, 10, 158, 120, 108, 152, 169, 181, 20, 84, 60, 11, 67, 4, 29, 113, 16, 162, 28, 192, 6, 47, 104, 148, 124, 106, 141, 90, 197, 48, 89, 139, 114, 86, 161, 25, 5, 1, 168, 194, 8, 46, 17, 69, 92, 59, 30, 117, 24, 72, 182, 103, 196, 137, 149, 63, 36, 55, 41, 132, 167, 119, 105, 32, 110, 190, 130, 134, 0, 18, 22, 73, 15, 135, 165, 7};

	// Same array as above..few elements are replaced with 50 and 100
	// to be used for 3 way quick sort
	int arr_dup[] = {100, 99, 95, 76, 183, 37, 121, 52, 186, 164, 153, 14, 58, 128, 116, 35, 77, 100, 123, 171, 199, 79, 54, 98, 180, 23, 151, 155, 187, 159, 97, 70, 189, 142, 140, 101, 150, 176, 27, 71, 56, 12, 107, 175, 173, 163, 82, 44, 45, 136, 80, 184, 3, 125, 111, 129, 154, 49, 138, 2, 96, 131, 26, 145, 93, 81, 68, 88, 33, 178, 170, 19, 50, 127, 50, 133, 21, 147, 39, 160, 43, 157, 185, 42, 156, 112, 65, 50, 64, 94, 109, 146, 9, 122, 31, 126, 50, 177, 87, 91, 50, 143, 102, 50, 179, 50, 198, 62, 34, 75, 78, 193, 83, 115, 100, 166, 74, 61, 191, 53, 13, 85, 174, 118, 195, 10, 158, 120, 108, 152, 169, 181, 20, 84, 60, 11, 67, 4, 29, 113, 16, 162, 28, 192, 6, 47, 104, 148, 124, 106, 141, 90, 197, 48, 89, 139, 114, 86, 161, 25, 5, 1, 168, 100, 8, 46, 17, 69, 100, 59, 30, 117, 24, 72, 182, 103, 196, 137, 149, 63, 36, 55, 41, 132, 167, 119, 105, 32, 110, 190, 130, 134, 0, 18, 22, 73, 15, 135, 100, 7};

	printf("%d , %d\n", arr[0], arr[199]);
	q_sort_algs(arr, 0, 199);
	printf("%d , %d\n", arr[0], arr[199]);
	//printf("%d , %d\n", arr[0], arr[199]);
	//q_sort_algs(arr_dup, 0, 199);
	//printf("%d , %d\n", arr[0], arr[199]);
	printf("%d , %d\n", arr_dup[0], arr_dup[199]);
	q_sort_3way_algs(arr_dup, 0, 199);
	printf("%d , %d\n", arr_dup[0], arr_dup[199]);
	return 0;
}

void q_sort_algs(int arr[], int low, int high)
{
	if(low>=high)
		return;

	int i = low;
	int j = high+1;
	int p = arr[low];

	while(1)
	{
		while(arr[++i] < p)
		{
			if(i == high)
				break;
		}

		while(arr[--j] > p)
		{
			if(j == low)
				break;
		}

		if(i>=j)
			break;

		// previous 2 while loops broke
		// i<j
		// we have a greater element at i and lesser element at j
		// exchange them
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	int tmp = arr[j];
	arr[j] = p;
	arr[low] = tmp;
	q_sort_algs(arr, low, j-1);
	q_sort_algs(arr, j+1, high);
}

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void q_sort_3way_algs(int arr[], int low, int high)
{
	if(low>=high)
		return;

	int lt = low;
	int gt = high;
	int i = low+1;
	int p = arr[low];

	// Invariant: Everything before i is equal to p, before lt is < p and after gt is > p
	while(i<=gt)
	{
		if(arr[i] < p)
		{
			// We know lt pointed element is = p
			// So, swap it with i and increment i
			// since current element is <p, increment lt
			swap(arr, lt++, i++);
		}
		else if(arr[i] > p)
		{
			// We dont know if gt pointed element is > or < or = to p
			// So, dont increment i
			swap(arr, i, gt--); 
		}
		else
		{
			// Current element is = p
			// Just increment i
			i++;
		}
	}
	// Everything to left of lt is < p
	// Everything to right of gt is >p
	// Remaining is in correct position
	// swapping already done 
	q_sort_3way_algs(arr, low, lt-1);
	q_sort_3way_algs(arr, gt+1, high);
}

