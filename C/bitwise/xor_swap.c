

Xor Swap
a = 101101
b = 110101

a ^= b
    011000 (same bits are set to 0, opposite bits set to 1)

b ^= a     (while xoring with now a, if 0 -> same bit as b, if 1 -> invert b bit)
    101101

a ^= b      same
    110101




In c, 
a = a+b
b = a-b
a = a-b

b = a+(a=b)-b
