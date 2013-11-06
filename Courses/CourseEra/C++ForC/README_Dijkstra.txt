This text details my approach to solve this assignment.

Files:
======
dijkstra_shortest_path_algo.h      - This file has the class & method declarations.
dijkstra_shortest_path_algo.cpp    - This file has the class & method definitions and main().

Compiling:
==========
On linux, I copied both files to same location, and compiled with this command:

g++ -Wall -O2 -std=c++11 dijkstra_shortest_path_algo.cpp -o dijkstra

Run the program with this command:

./dijkstra

Class diagram:
==============
This is the code flow.

main() -> GraphGenerate::generate_and_simulate(x,y,z) -> Create Graph(x) -> ShortestPath(Graph)

Approach:
=========
=========

Graph:
=====
Graph data type is represented as 'Graph' class.
Graph class mainly contains a set of edge lists along with some helper methods.

Dijkstra's:
===========
A fully constructed graph is passed to 'ShortestPath' class as a parameter.
This class stores distances of each vertex from vertex 1.
Also provides methods to perform Dijkstra's algorithm on the graph passed.

Dijkstra's algo was implemented as a variant of BFS. Queue in BFS is replaced with Priority Queue.

Simulation:
===========
GraphGenerate class performs the necessary simulation on a Graph with vertex size 50. In the code, number of simulations is 1000. It can be modified to change the number.

The simulation iterates through all the possible undirected edges [ (N*N-1/2)*2 ] , if a random number for that iteration is less than density, an edge is added with random value chosen from 1.0 - 10.0.

Shortest distance is calculated for each vetex from vertex 1. They are added and sum is divided by the number of reachable vertices.

This process is repeated multiple times and avg value is the total avg path length. 

This approach is taken as per the post from Mike Roberts (COMMUNITY TA). This is the link for the same - https://class.coursera.org/cplusplus4c-002/forum/thread?thread_id=321 

Note: In the comments & variable names, I mentioned both edge length and edge weight some times. They are the same things. 
=====


Simulation results:
==================
Files compiled with 'g++ -Wall -O2 -std=c++11 dijkstra_shortest_path_algo.cpp -o dijkstra'


Simulation count : 1000

Generating graph with density 0.2 and running simulation
Avg path length when edge density is 0.2: 5.74312
Generating graph with density 0.4 and running simulation
Avg path length when edge density is 0.4: 3.6801

Time taken to run : 4.4 sec.
CPU: Core2 Duo, 1.66 GHz


Simulation count : 10000

Generating graph with density 0.2 and running simulation
Avg path length when edge density is 0.2: 5.71751
Generating graph with density 0.4 and running simulation
Avg path length when edge density is 0.4: 3.6368

Time taken to run: 44 sec.
CPU: Core2 Duo, 1.66 GHz

