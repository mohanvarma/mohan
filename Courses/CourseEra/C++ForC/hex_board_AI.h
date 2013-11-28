#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

// Structure representing an edge of a graph
struct graphEdge
{
	// vertex
	int vertex;

	//value associated with edge
	double val;

	// color of that edge
	// 0 for blue, 1 for red
	// I was able to finish this assignment without using this variable.
	// As, I stored 2 players info in 2 separate graphs.
	int color;
};

// This is the main data type storing the graph as edge lists

// typedef to store vector of( vector of (edges))
// edge contains node, corresponding edge weight and colour of hex_board player(Blue/Red)
// So, each vertex has an edge_list, each entry in the edge_list has a edge with first value 
// containing the vertex index, second value containing weight of the edge 
// and third value containing edge color(Blue/Red)
//
typedef vector<vector<graphEdge > > vector_of_vector_of_edges;

typedef vector<graphEdge > vector_of_edges;


// Graph data type
class Graph
{
public:

	int edges;    // No. of edges
	int vertices; // No. of vertices
	vector_of_vector_of_edges edge_lists; // edge_lists of each vertex

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
	double get_edge_value(int x, int y);

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
	bool short_path(int x, int y, vector<double>& path,
			const Graph& g);

	// Returns path size
	int path_size(int x, int y);

};

// By default, STL priority queue returns max value from top
// But, we need a node with min edge distance, so declaring a
// comparator class as needed by priority_queue
// This compares 2 MstEdges by their edge values(edge weights)

// I got to know about this functor usage concept from stackoverflow.com
class CompareEdges
{
public:
	int operator() (const graphEdge& e1, const graphEdge& e2)
	{
		return e1.val > e2.val;
	}
};

// This class was used to test dijksta's algo
// with some known graphs given in coursera forums
// Here is the link (https://class.coursera.org/cplusplus4c-002/forum/thread?thread_id=203)
class LocalTesting
{
public:
	void Test();
};

// class representing the hex board of dimention p X p
class HexBoard
{
public:
	// Variable to hold board dimention
	int dimention;

	// Holds the move number
	int moveNumber;

	// vector representing blue vertices
	vector<int> blueVertices;

	// vector representing red vertices
	vector<int> redVertices;

	// HexBoard constructor
	HexBoard(int dimention);

	// Method to print the board with current
	// configuration
	void print_board();

	// Take input
	// Validates input and adds to board
	// and returns true
	// or returns false to indicate error
	//
	// 0 for blue, 1 for red
	bool take_input(pair<int, int> p, int player, Graph& g, string str);

	// Method to determine if a player wins
	// 0 for blue, 1 for red
	bool is_win(int player, Graph& g); 

	// This returns a vector of strings containing 
	// xy coordinates of neighbours of a vertex
	vector<pair<int, int> > get_neighbours(pair<int, int> p);
};

// This class contains helper methods to transform
// hexboard coordinates to linear and vice versa
// used by other class methods
class Helper
{
public:
	// Transforms coordinates to linear value
	// This is used to easily store a move in blue/red vertices vector.
	static int xy_to_linear(pair<int, int> p, int dimention);

	// Transforms linear value to coordinates string
	static pair<int, int> linear_to_xy(int num, int dimention);
};
