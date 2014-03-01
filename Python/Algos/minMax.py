import time
import sys

fp = open("minMax.txt", "r")
arr = []
for i in fp.readlines():
    arr.append(int(i))

tic = time.clock()
min_ele = min(arr)
toc = time.clock()

print "Builtin min:", min_ele, "Took:", toc-tic, "Secs"

tic = time.clock()
max_ele = max(arr)
toc = time.clock()

print "Builtin max:", max_ele, "Took:", toc-tic, "Secs"

tic = time.clock()
min_ele = sys.maxint
for i in arr:
    if i<min_ele:
        min_ele = i

toc = time.clock()

print "my min:", min_ele, "Took:", toc-tic, "Secs"

tic = time.clock()
max_ele = -sys.maxint
for i in arr:
    if i>max_ele:
        max_ele = i

toc = time.clock()

print "my max:", max_ele, "Took:", toc-tic, "Secs"

tic = time.clock()
min_ele = sys.maxint
for i in arr:
    if i<min_ele:
        min_ele = i
max_ele = -sys.maxint
for i in arr:
    if i>max_ele:
        max_ele = i

toc = time.clock()

print "Min max:", min_ele, max_ele, "Took:" , toc-tic, "Secs"

tic = time.clock()

min_ele = sys.maxint
max_ele = -sys.maxint

last = len(arr)/2

j = 0
for i in range(0,last):
    if(arr[j]<arr[j+1]):
        if(arr[j]<min_ele):
            min_ele = arr[j]
        if(arr[j+1]>max_ele):
            max_ele = arr[j+1]
    else:
        if(arr[j+1]<min_ele):
            min_ele = arr[j+1]
        if(arr[j] > max_ele):
            max_ele = arr[j]
    j += 2
if j<(len(arr)-1):
    # last element left, compare
    print "Last element left"
    if (arr[len(arr)-1]<min_ele):
        min_ele = arr[len(arr)-1]
    if (arr[len(arr)-1]>max_ele):
        max_ele = arr[len(arr)-1]

toc = time.clock()

print "Min max Algo:", min_ele, max_ele, "Took:", toc-tic, "Secs"
