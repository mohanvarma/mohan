from collections import deque
q = deque([])
q.append(1)
q.append(2)
q.append(3)
q.append(4)
print q
q.popleft()
print q
#This will always be used for pushing items
s1 = []
#This will always be used for popping items
# Whenever this is empty pop elements from s1 and push them here, so reverse order is created
# If not empty, reverse order was already created earlier, so keep popping()
s2 = []
# If both are empty, underflow, error
# Using 2 stacks above
def push_queue(n):
    s1.append(n)
    print 'Pushing: ', n
def pop_queue():
    if(len(s2) == 0 and len(s1) == 0):
        print 'Error'
        return
    #if s2 is empty fetch from s1, in reverse order
    if len(s2) == 0:
        while(len(s1)>0):
            s2.append(s1.pop())
    print "Popping:", s2.pop()
def main():
    push_queue(1)
    print s1, s2
    pop_queue()
    print s1, s2
    pop_queue()
    print s1, s2
    push_queue(1)
    print s1, s2
    push_queue(2)
    print s1, s2
    push_queue(3)
    print s1, s2
    pop_queue()
    print s1, s2
    push_queue(4)
    print s1, s2
    pop_queue()
    print s1, s2
    pop_queue()
    print s1, s2
    pop_queue()
    print s1, s2
if __name__=="__main__":
    main()
