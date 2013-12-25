import random
lst = [1,-2,9,89,0,97,65,23,45,-76,-98,-0,89,2,6,45,43]
print lst

def ins_sort(lst):
    for i in range(1, len(lst)):
        key = lst[i]
        j = i-1
        while j>=0 and key<lst[j]:
            lst[j+1] = lst[j]
            j = j-1
        lst[j+1] = key

def inef_sort(lst):
    for i in range(0, len(lst)):
        for j in range(i+1, len(lst)):
            if lst[i] < lst[j]:
                lst[i], lst[j] = lst[j], lst[i]
#ins_sort(lst)
inef_sort(lst)
print lst
