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



## Merge sort to count inversions

def count_split_inversions(lst, low, high):
    i,j = 0,0
    tmp = lst[:]
    mid = (low+high)/2

    i = low
    j = mid+1
    inv = 0

    for k in range(low, high+1):
	if i<mid+1 and j<high+1:
	    if tmp[i] < tmp[j]:
	        lst[k] = tmp[i]
	        i = i+1
	    else:
	        lst[k] = tmp[j]
	        j = j+1
	        # This is the number of split inv
	        # Whenever 1 element from the right half is copied, it creates inversions 
	        # equal to the no. of remaining elements in the left half
	        # in any other case, since left half & right half are already sorted(and inversions computed) by the recursive
	        # calls(see the sort and count function), so no need to consider inversions
	        inv = inv+(mid-i+1)
	elif i>mid and j<high+1:
	    lst[k] = tmp[j]
	    j = j+1
	elif i<mid+1 and j>high:
	    lst[k] = tmp[i]
	    i = i+1
    return inv
    
def sort_and_count(lst, low, high):

    if low==high or low>high:
        return 0

    #low, high inclusive
    mid = (low+high)/2

    x = sort_and_count(lst, low, mid)
    y = sort_and_count(lst, mid+1, high)
    z = count_split_inversions(lst, low, high)
    if low == 0 and high == 99999:
        print "Left half:", x , "Right half:", y, "Split:", z
    return x+y+z

tic = time.clock()
i = sort_and_count(array, 0, 99999)
toc = time.clock()

print array[0]
print array[99999]
print i
print "Time taken for merge:", toc-tic
