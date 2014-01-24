import sys
import time
import random
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

copy_array = array[:]

tic = time.clock()
quick_sort(array, 0, len(array)-1)
#array = quick_sort_lists(array)
toc = time.clock()

print array[0]
print array[99999]
print "Time taken for quick sort:", toc-tic


""" Finding nth order statistic(nth largest)(median for n = length/2)
in linear time using quicksort idea
"""
def Rselect(lst, low, high, n):
    if low<high:
            # Get pivot index
            pivot = Rselect_partition(lst, low, high)
            print pivot,low, high, n

            # If we get lucky, partition function finds the pivot
            # index to be nth order statistic, because partition
            # sets pivot in such that, left-of lst < pivot < right-of lst

            # correct position should be , pos = high-(n-1)
            pos = high-(n-1)
            if pivot == pos:
                return lst[pos]

            # If the index chosen as pivot is less than n
            # we have to search for nth statistic in the right side of lst
            # because, all the elements to the right of the pivot, are greater   
            # n wont change
            if pivot < pos:
                print pivot, "<", pos
                print pivot+1, high, n
                return Rselect(lst, pivot+1, high, n)
            # Else, pivot is greater than n(pos), we can eliminate some numbers
            # from the nth order statistic, as there are some numbers greater than pivot to
            # the right side.
            # we can eliminate high-pivot numbers and 1 for the pivot itself
            else:
                print pivot, ">", pos
                print low, pivot-1, n-(high-pivot)-1
                return Rselect(lst, low, pivot-1, n-(high-pivot)-1)
    elif low==high:
        if low == (high-(n-1)):
            return lst[low]
       
   

def Rselect_partition(lst, low, high):
    pivot = random.randint(low, high)
    # swap it with last element
    lst[pivot], lst[high] = lst[high], lst[pivot]

    pivot = high
    i = low-1
    for j in range(low, high):
        if lst[j] <= lst[pivot]:
            i += 1
            lst[i], lst[j] = lst[j], lst[i]
    lst[i+1], lst[pivot] = lst[pivot], lst[i+1]
    #print lst, lst[i+1]
    return i+1

temp = [x for x in range(20)]
random.shuffle(temp)
#print temp
tic = time.clock()
n = Rselect(copy_array, 0, len(copy_array)-1, 50000)
toc = time.clock()

print "Time taken for Rselect:", toc-tic, "Nth order statistic:", n
