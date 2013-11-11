Files:
======
prims_algo.h    - Contains class declarations
prims_algo.cpp  - Contains method definitions and main.

Compiling:
==========
I compiled this program in Linux.
Copy both files to same directory and compile with the following command.
g++ -std=c++11 prims_algo.cpp

To run the program,

./a.out

Running on sample data:
=======================
Ran the program on sample data mentioned in the assignment,

$ ./a.out 
Enter the name of the graph input file: input_2.txt
Total MST Cost: 30
0   2   2   
2   0   2   
1   17  1   
17  1   1   
2   9   1   
9   2   1   
4   7   1   
7   4   1   
4   15  2   
15  4   2   
5   6   1   
6   5   1   
5   18  1   
18  5   1   
6   1   1   
1   6   1   
7   10  2   
10  7   2   
8   4   1   
4   8   1   
9   8   3   
8   9   3   
9   13  3   
13  9   3   
10  16  3   
16  10  3   
12  3   1   
3   12  1   
14  11  1   
11  14  1   
15  19  2   
19  15  2   
16  5   2   
5   16  2   
17  12  1   
12  17  1   
18  14  1   
14  18  1   
