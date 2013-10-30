#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<limits>
#include<cstdlib>

using namespace std;

// We run simulation on a graph with 50 vertices
const int VERTICES = 50;

// This is the main data type storing the graph as edge lists

// typedef to store vector of( vector of (pairs))
// pair contains node and corresponding edge weight
// So, each vertex has an edge_list, each entry in the edge_list has a pair with first value 
// containing the vertex index and second value containing weight of the edge
//
typedef vector<vector<pair<int, double> > > vector_of_vector_of_pairs;

typedef vector<pair<int, double> > vector_of_pairs;


// Graph data type
class Graph
{
public:

	int edges;    // No. of edges
	int vertices; // No. of vertices
	vector_of_vector_of_pairs edge_lists; // edge_lists of each vertex

	// Constructor
	Graph(int vertices);

	// Returns number of vertices
	int get_vertex_count();

	// Returns number of edges
	int get_edge_count();

	// Returns true if vertex x is adjacent to vertex y
	bool is_adjacent(int x, int y);

	// Returns(Modifies the passed reference) list of neighbours of y
	void neighbours(int x, vector<int>& list);

	// Add edge x<->y
	void add_edge(int x, int y);

	// Delete edge x<->y
	void delete_edge(int x, int y);

	// Gets value of the edge x<->y
	int get_edge_value(int x, int y);

	// Sets value of the edge x<->y
	void set_edge_value(int x, int y, double val);

};

// Class performing Dijksta's algorithm on a 'Graph' class
//
class ShortestPath
{
public:

	vector<int> path; // vector representing the sequence of vertices(path)
	int path_length; // path cost

	vector<double> distance; // vector of distances
	vector<int> parent; // vector of parent nodes. parent[i] gives the parent of i
	                    // This vector will be used to backtrack from destination to construct path

	// Constructor of ShortestPath Class
	// Graph class instance is passed as a reference.
	ShortestPath(const Graph& g);

	// Returns(modifies the passed reference) sequence of vertices
	// in the path from x to y
	void short_path(int x, int y, vector<double>& path,
			const Graph& g);

	// Returns path size
	int path_size(int x, int y);

};

// By default, STL priority queue returns max value from top
// But, we need a node with min edge distance, so declaring a 
// comparator class as needed by priority_queue
// This compares 2 pairs by their second values(edge weights)
class ComparePairs
{
public:
	int operator() (const pair<int, double>& p1, const pair<int, double> &p2)
	{
		return p1.second > p2.second;
	}
};

// Main class which generates a graph with 50 vertices 
// and performs simulation
class GraphGenerate
{
public:
	// Main method where graph is constructed and simulations are run
	// returns avg of all simulations
	// Input: no. of vertices, graph density, no. of simulations to perform
	// in above order
	double generate_and_simulate(int vertices, double density, unsigned int simulations);
};

// This class was used to test dijksta's algo
// with some known graphs given in coursera forums
// Here is the link (https://class.coursera.org/cplusplus4c-002/forum/thread?thread_id=203)
class LocalTesting
{
public:
	void Test();
};

