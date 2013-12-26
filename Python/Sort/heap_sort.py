import sys
import time

array = []
sorted_array = []
fp = open("IntegerArray.txt", "r")
for i in fp.readlines():
    array.append(int(i))

#print array[0]
#print array[len(array)-1]
#print len(array)

"""
using list to represent a heap structure
parent of i is (i-1)/2
left of i is 2i+1
right of i is 2i+2
"""
def parent(arr, i):
    return (i-1)/2

def left(arr, i):
    return 2*i+1

def right(arr, i):
    return 2*i+2

"""
We call this when left(i) and right(i) are max_heaps
but root is lesser then them.
This procedure floats down until the leaf nodes
So this is used on a heap constructed bottom up
replace > with >= in left, right comparison, to handle duplicates
"""
def max_heapify(arr,i):
    l = left(arr, i)
    r = right(arr, i)
    greater = 0
    
    #compare with left 
    if l<=(len(arr)-1) and arr[l]>arr[i]:
        greater = l
    else:
        greater = i

    #compare with right
    if r<=(len(arr)-1) and arr[r]>arr[greater]:
        greater = r

    #swap the current node with greater
    if not arr[greater]==arr[i]:
        arr[greater], arr[i] = arr[i], arr[greater]
        #recurse down the heap with exchaged element
	max_heapify(arr, greater)
"""
As per the definition of heap structure,
all leaf nodes start from n/2....n where n is 
size of the heap
since leaves are trivial heaps,
max_heapify is called on all root nodes from n/2...1
This procedure constructs a max_heap from a heap
"""
def build_max_heap(arr):
    heapSize = len(arr)
    lastNonLeafIndex = ((heapSize+1)/2)-1
    #print lastNonLeafIndex
    for i in range(lastNonLeafIndex, -1 , -1):
	max_heapify(arr, i)

"""
HeapSort:
First build a max_heap from heap
->
Then swap 1st and last elements of heap
and pop the last element and reduce the heap size by 1
This may result in violation of heap property at root, but children remain valid heaps
So, do max_heapify(root)
->
Repeat above procedure for all elements from last to 1
"""
def heap_sort(arr):
    # Now, build max_heap from array
    build_max_heap(arr)
    print "-------------------"
    print array[0]
    print array[len(array)-1]
    heap_len = len(arr)
    for i in range(heap_len, 0, -1):
	arr[0], arr[len(arr)-1] = arr[len(arr)-1], arr[0]
	elmt = arr.pop()
	sorted_array.append(elmt)
	if len(arr) > 0:
	    max_heapify(arr, 0)
	
tic = time.clock()
heap_sort(array)
toc = time.clock()
print "-------------------"
print len(sorted_array)
print sorted_array[0]
print sorted_array[len(sorted_array)-1]
print "Sort took:", toc-tic, "secs"

