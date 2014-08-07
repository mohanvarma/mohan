# read from file and return ints as a list
def readfile(txt):
    ints = []
    for i in open(txt).readlines():
	ints.append(int(i))
    return ints

# merge, as well as count inversions while sorting
def sortAndCountSplitInv(ints, low, high):
    mid = (low+high)/2
    i = low
    j = mid+1
    k = low
    temp = ints[:]
    count = 0

    while(k<=high):
	if(i<=mid and j<=high):
	    if(temp[i] < temp[j]):
		ints[k] = temp[i]
		i+=1
		k+=1
		continue
	    elif(temp[i] > temp[j]):
		ints[k] = temp[j]
		# Add no. of remaining ints in the left half to split invs
		count = count + ((mid-i)+1)
		j+=1
		k+=1
		continue
	elif(i>mid and j<=high):
	    ints[k] = temp[j]
	    j+=1
	    k+=1
	    continue
	elif(j>high and i<=mid):
	    ints[k] = temp[i]
	    i+=1
	    k+=1
	    continue
    return count

# count the number of inversions in the file
def countInversions(ints, low, high):
    # base case for recursion
    if(low>=high):
	return 0

    mid = (low+high)/2
    # recursively count inversions in the left,righ side
    leftInv = countInversions(ints, low, mid)
    rightInv = countInversions(ints, mid+1, high)

    # count the split inversions
    splitInv = sortAndCountSplitInv(ints, low, high)

    # return the total count
    return leftInv+rightInv+splitInv

if(__name__ == "__main__"):
    ints = readfile("IntegerArray.txt")
    count = countInversions(ints, 0, len(ints)-1)
    print "No. of inversions:", count





