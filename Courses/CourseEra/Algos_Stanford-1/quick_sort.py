import sys

fp = open("QuickSort.txt", "r")
array = []

for i in fp.readlines():
    array.append(int(i))

PIVOT_FIRST = 1
PIVOT_LAST = 2
PIVOT_MEDIAN = 3

comparisons = 0

# In range [low, high], so low and high inclusive
def quick_sort(arr, low, high, pivot):
    if (low<high):
        if (PIVOT_FIRST == pivot):
            p = arr[low]
	
	elif (PIVOT_LAST == pivot):
	    p = arr[high]
	    arr[low], arr[high] = arr[high], arr[low]
	else:
	    mid = median(arr, low, high)
	    p = arr[mid]
	    if(not mid == low):
	        arr[low], arr[mid] = arr[mid], arr[low]

	# No. of comparisons == no. of elements in this array -1 for pivot
	global comparisons
	comparisons += (high-low)
	pos = quick_sort_partition(arr, low, high, p)
	quick_sort(arr, low, pos-1, pivot)
	quick_sort(arr, pos+1, high, pivot)

def quick_sort_partition(arr, low, high, pivot):
    i = low+1
    j = 0
    for j in range(low+1, high+1):
	if (arr[j] < pivot):
	    arr[j], arr[i] = arr[i], arr[j]
	    i = i+1
    arr[low], arr[i-1] = arr[i-1], arr[low]
    return i-1

def median(arr, low, high):
    l = low
    h = high
    m = low+ ((high-low)/2)

    lst = []
    lst.append(arr[l])
    lst.append(arr[h])
    lst.append(arr[m])

    lst.sort()


    if lst[1] == array[h]:
        return h
    elif lst[1] == array[l]:
        return l
    else:
        return m    

quick_sort(array[:], 0, len(array)-1, PIVOT_FIRST)

#print array[0]
#print array[len(array)-1]
print "Comparisons:", comparisons

comparisons = 0

quick_sort(array[:], 0, len(array)-1, PIVOT_LAST)

#print array[0]
#print array[len(array)-1]
print "Comparisons:", comparisons

comparisons = 0

quick_sort(array, 0, len(array)-1, PIVOT_MEDIAN)
print array[0]
print array[len(array)-1]

#array_temp = [8,2,4,5,7,1]
#quick_sort(array_temp, 0, len(array_temp)-1, PIVOT_MEDIAN)
print "Comparisons:", comparisons
