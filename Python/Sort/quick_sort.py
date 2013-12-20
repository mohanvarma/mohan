import sys
import time
ins = open( "IntegerArray.txt", "r" )
array = []
num = 0
tic = time.clock()
for line in ins:
	if num<100000:
		array.append( int(line) )
    		num = num+1
toc = time.clock()
print "Time taken to read:", toc-tic

#tic = time.clock()
#array.sort()
#toc = time.clock()

#print array[1]
#print array[99999]
#print "Time taken:", toc-tic


'''
Quick sort
'''

def quick_sort(lst, low, high):
    if low<high:
        # recursively sort less and more arrays around partition
        p = quick_sort_partition(lst, low, high)
        quick_sort(lst, low, p-1)
        quick_sort(lst, p+1, high)

def quick_sort_partition(lst, low, high):
    pivot = lst[high]
    # i is the last index of array of all lesser elements
    # j is the last index of array of all greater elements
    i = low-1
    for j in range(low, high):
        if lst[j] <= pivot:
            i = i+1
            # lesser element found, swap it with incremented i
            lst[i], lst[j] = lst[j], lst[i]
    # we're choosing last element as pivot, so swap it with correct position
    # which is the next element to current i
    lst[i+1], lst[high] = lst[high], lst[i+1]
    return i+1

def quick_sort_lists(lst):
    if len(lst) <= 1:
        # trivial case 
        return lst
    pivot = lst[len(lst)-1]
    #recursively sort less and more
    less = quick_sort_lists([x for x in lst[:len(lst)-1] if x <= pivot])
    more = quick_sort_lists([x for x in lst[:len(lst)-1] if x > pivot])
    equal = [pivot]
    return less+equal+more

tic = time.clock()
quick_sort(array, 0, len(array)-1)
#array = quick_sort_lists(array)
toc = time.clock()

print array[0]
print array[99999]
print "Time taken for quick sort:", toc-tic
