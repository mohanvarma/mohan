import sys
import time
#RANGE = 6

array = []

#fp = open("CountingSort.txt", "r")
#Integer array is appended twice to create IntegerArray2.txt
fp = open("IntegerArray2.txt", "r")
for i in fp.readlines():
    array.append(int(i))

RANGE = len(array)/2+1
# We know all elements are in the range 0-100k
aux_storage = [0]*RANGE
sorted_array = [0]*len(array)

"""
Counting sort:
Uses an auxiliary storage space, no. of elements less than 
the current element, so by determining the position of current element to insert
in a new sorted array
"""
def counting_sort(orig_arr, sorted_arr, aux_arr):

    # Array counting frequencies of each element
    for i in range(0, len(orig_arr)):
	aux_arr[orig_arr[i]] = aux_arr[orig_arr[i]]+1

    # Counting all elements less than the current element
    for i in range(1, len(aux_arr)):
	aux_arr[i] = aux_arr[i-1]+aux_arr[i]

    # Put element in the correct position
    for i in range(len(orig_arr)-1, -1, -1):
	sorted_arr[aux_arr[orig_arr[i]]-1] = orig_arr[i]
        # reduce the position index by 1
	aux_arr[orig_arr[i]] = aux_arr[orig_arr[i]]-1

tic = time.clock()
counting_sort(array, sorted_array, aux_storage)
toc = time.clock()
print sorted_array[0]
print sorted_array[23456]
print sorted_array[99999]
print sorted_array[199999]
print "Couting sort took:", toc-tic, "secs"
