inp = raw_input().split()
n = int(inp[0])
k = int(inp[1])

lst1 = raw_input().split()

for i in range(len(lst1)):
    lst1[i] = int(lst1[i])

lst2 = [l+k for l in lst1]
final = set(lst1).intersection(lst2)

print len(final)

