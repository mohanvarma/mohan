#include<time.h>

#define FIRST 

#ifdef FIRST

#include<stdio.h>
#include<stdlib.h>
int arr[100000];
void merge(int arr[], int low, int high);
void merge_sort(int arr[], int low, int high);
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
//Bubble sort
/*
for(i=0; i<(100000-1); i++)
{
for(j=0; (j+1)<(100000-i); j++)
{
if(arr[j] > arr[j+1])
{
int tmp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = tmp;
}
}
}
*/
//bubble_sort(arr, 100000);

start = clock();

merge_sort(arr, 0, 99999);

end = clock();

printf("Merge took %f secs when mallocd temp arrays \n", 1.0*(end-start)/CLOCKS_PER_SEC);

printf("%d\n", arr[0]);
printf("%d\n", arr[1]);
printf("%d\n", arr[2]);
printf("%d\n", arr[59983]);
printf("%d\n", arr[count-3]);
printf("%d\n", arr[count-2]);
printf("%d\n", arr[count-1]);
getchar();
return 0;
}

/* MAIN ALGO
 *
//low, high are inclusive.
void merge(int arr[], low, high)
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
j++
k++;
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
void merge_sort(int arr[], int low, int high)
{
int mid;

if(low==high || low>high)
return;

mid = (low+high)/2;
merge_sort(arr[], low, mid);
merge_sort(arr[], mid+1, high);
merge(arr, low, high);
}
*/

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

#endif

#ifdef SECOND

#include<stdio.h>
#include<stdlib.h>
int arr[100000];
int arr2[100000];
void merge(int arr[], int low, int high, int arr2[]);
void merge_sort(int arr[], int low, int high, int arr2[]);
#define COPY_MERGED(arr2, low, high, arr, k) for(k=low; k<=high; k++) arr[k] = arr2[k];

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
//Bubble sort
/*
for(i=0; i<(100000-1); i++)
{
for(j=0; (j+1)<(100000-i); j++)
{
if(arr[j] > arr[j+1])
{
int tmp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = tmp;
}
}
}
*/
//bubble_sort(arr, 100000);
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
getchar();
return 0;
}

/* MAIN ALGO
 *
//low, high are inclusive.
void merge(int arr[], low, high)
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
j++
k++;
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
void merge_sort(int arr[], int low, int high)
{
int mid;

if(low==high || low>high)
return;

mid = (low+high)/2;
merge_sort(arr[], low, mid);
merge_sort(arr[], mid+1, high);
merge(arr, low, high);
}
*/

//low, high are inclusive.
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

#endif
