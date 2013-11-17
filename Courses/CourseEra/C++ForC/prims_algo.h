// This file includes class and method definitions
// for Graph and MstEdge data structures and
// PrimsAlgo class computing MST of a given
// complete graph.

#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<limits>
#include<cstdlib>
#include<fstream>

using namespace std;

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
	vector_of_vector_of_pairs edgeLists; // edgeLists of each vertex

	// Constructor
	// Takes filename where graph data is stored
	Graph(string fileName);

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
	double get_edge_value(int x, int y);

	// Sets value of the edge x<->y
	void set_edge_value(int x, int y, double val);

	// Compuetes MST of the graph
	void compute_mst();

};

// Structure representing an edge of a MST
struct MstEdge
{
	// src vertex
	int src;

	// destination vertex
	int dst;

	//value associated with edge src<->dst
	double val;
};

// By default, STL priority queue returns max value from top
// But, we need a node with min edge distance, so declaring a
// comparator class as needed by priority_queue
// This compares 2 MstEdges by their edge values(edge weights)

// I got to know about this functor usage concept from stackoverflow.com
class CompareEdges
{
public:
	int operator() (const MstEdge& e1, const MstEdge& e2)
	{
		return e1.val > e2.val;
	}
};

// Main class performing Prim's Algorithm
class PrimsAlgo
{
public:
	// vector of vertices representing MST.
	vector<int> mstVertices;

	// edge lists representing edges of MST.
	vector_of_vector_of_pairs mstEdgeLists;

	// Holds total mst cost
	double mstCost; 

	// Method computing MST of a given graph
	void mst_of_graph(Graph& g);
};


