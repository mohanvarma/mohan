  // hex_board.cpp - This file contains methods for creating 
// and processing a graph data type, finding shortest path and finally 
// using dijkstra's shortest path algo, deciding winning player in the
// hex board game.

// To, know more about what each of the following methods does,
// refer to 'hex_board.h' file.
//

#include "hex_board_AI.h"
#include <string.h>

// Graph constructor
Graph::Graph(int x)
{
    vertices = x;
    edges = 0;
    edge_lists.resize(x);
}

// Returns vertex count
int Graph::get_vertex_count()
{
    return vertices;
}

// Returns edge count 
int Graph::get_edge_count()
{
    return edges;
}

// Returns true if vertices x,y are adjacent and false otherwise`
bool Graph::is_adjacent(int x, int y)
{
    // Check if adge_lists[x] contains y
    for(unsigned int j = 0; j < edge_lists[x].size(); j++)
    {
	if(edge_lists[x][j].vertex == y)
	{
	    return true;
	}
    }
    return false;
}        

// Returns a vector of neightbouring vertices
void Graph::neighbours(int x, vector<int>& list)
{
    list.clear();

    // Add all the members of edge_lists[x] to the list vector
    for(unsigned int i = 0; i < edge_lists[x].size(); i++)
    {
	list.push_back(edge_lists[x][i].vertex);
    }
}

// Adds an edge x<->y to the graph
void Graph::add_edge(int x, int y)
{
    //add_edge with value -1
    graphEdge edge;
    edge.vertex = y;
    edge.val = -1;
    edge_lists[x].push_back(edge);

    //Increment the edge count
    edges++;
}

// Deletes an edge x<->y from the graph
void Graph::delete_edge(int x, int y)
{
    //Iterator of vector_of_edges
    vector_of_edges::iterator ite;
    for(ite = edge_lists[x].begin(); ite != edge_lists[x].end(); ite++)
    {
	if(ite->vertex == y)
	{
	    ite = edge_lists[x].erase(ite);

	    //Decrement the edge count
	    edges--;
	    return;
	}
    }
}

// Gets the value associated with edge x<->y
double Graph::get_edge_value(int x, int y)
{
    // Itereate all the members of edge_lists[x] and return
    // the edge_weight from the matched edge
    for(unsigned int j = 0; j < edge_lists[x].size(); j++)
    {
	if(edge_lists[x][j].vertex == y)
	{
	    return edge_lists[x][j].val;
	}
    }

    // For a correctly constructed graph, code should never reach here
    // But just in case, we return the infinity value
    return numeric_limits<double>::max();
}

// Sets the value associated with edge x<->y
void Graph::set_edge_value(int x, int y, double val)
{
    // Itereate all the members of edge_lists[x] and set
    // the edge_weight for the matched edge
    for(unsigned int j = 0; j < edge_lists[x].size(); j++)
    {
	if(edge_lists[x][j].vertex == y)
	{
	    edge_lists[x][j].val = val;
	}
    }
}

// Constructor of ShortestPath class
ShortestPath::ShortestPath(const Graph& g)
{
    vector_of_vector_of_edges edge_lists = g.edge_lists;
    distance.resize(edge_lists.size());
    parent.resize(edge_lists.size());

    for(unsigned int i = 0; i < distance.size(); i++)
    {
	// Closest thing to infinity
	// max possible value of double
	distance[i] = numeric_limits<double>::max();

	// Initialize parent vector
	parent[i] = -1;
    }
}

// Method computing the shortest path
bool ShortestPath::short_path(int x, int y, vector<double>& path,
		const Graph& g)
{
    vector_of_vector_of_edges edge_list = g.edge_lists;

    // Using priority queue from STL
    // It returns least value by default, so modifying it
    // by using Comparator class for returning max value
    priority_queue<graphEdge, vector<graphEdge> , CompareEdges> pq;

    distance[x] = 0;

    //Push pair<x, edge value> to the pq
    graphEdge edge;
    edge.vertex = x;
    edge.val = distance[x];
    pq.push(edge);

    // while pq is not empty
    // Dijkstra's algorithm.
    while(!pq.empty())
    {
	// Get the least weight edge
	int vertex = pq.top().vertex;

	//If vertex itself is the required destination, stop the process
	if(vertex == y)
	{
	    break;
	}

	// Else, remove this vertex from pq and add all neighbouring edges to pq
	pq.pop();

	for(unsigned int i=0; i < edge_list[vertex].size(); i++)
	{
	    int neighbour = edge_list[vertex][i].vertex;
	    double weight = edge_list[vertex][i].val;

	    // If distance travelled to destination through
	    // 'vertex' is better than direct distance
	    // update it
	    if((distance[vertex] != numeric_limits<double>::max()) && distance[neighbour] > (distance[vertex]+weight))
	    {
		distance[neighbour] = distance[vertex]+weight;
		parent[neighbour] = vertex;

		// Push neighbour and it's updated distace to pq
		graphEdge edge;
		edge.vertex = neighbour;
		edge.val = distance[neighbour];
		pq.push(edge);
	    }
	}
    }

    // Backtrack the parent vector to find path
    path.clear();

    int destination = y;
    int count = 0;
    // Modified usual dijkstra.
    // if parent[destination] is -1, return failure.
    while(destination != x && count<g.vertices)
    {
	count++;
	destination = parent[destination];
	if(destination == -1)
	{
	    return false;
	}
	path.push_back(destination);
    }

    // check if the count is overflowing
    if(count == g.vertices)
    {
	return false;
    }

    return true;
}

// Test method used to test dijkstra shortest path algo.
void LocalTesting::Test()
{
    //Sample test_case 1

    /*
       Graph g(4);

       g.add_edge(0, 1);
       g.add_edge(0, 3);

       g.set_edge_value(0, 1, 1);
       g.set_edge_value(0, 3, 4);

       g.add_edge(1, 0);
       g.add_edge(1, 2);

       g.set_edge_value(1, 0, 1);
       g.set_edge_value(1, 2, 1);

       g.add_edge(2, 1);
       g.add_edge(2, 3);

       g.set_edge_value(2, 1, 1);
       g.set_edge_value(2, 3, 1);

       g.add_edge(3, 0);
       g.add_edge(3, 2);

       g.set_edge_value(3, 0, 4);
       g.set_edge_value(3, 2, 1);
       */

    //Sample test_case 2

    /*
       Graph g(3);

       g.add_edge(0,1);
       g.add_edge(1,0);

       g.set_edge_value(0, 1, 1);
       g.set_edge_value(1, 0, 1);

       g.add_edge(1,2);
       g.add_edge(2,1);

       g.set_edge_value(1, 2, 1);
       g.set_edge_value(2, 1, 1);

       g.add_edge(0,2);
       g.add_edge(2,0);

       g.set_edge_value(0, 2, 3);
       g.set_edge_value(2, 0, 3);
       */

    //Sample test_case 3
    Graph g(6);
    g.add_edge(0, 1);
    g.set_edge_value(0, 1, 7);

    g.add_edge(0, 2);
    g.set_edge_value(0, 2, 9);

    g.add_edge(0, 5);
    g.set_edge_value(0, 5, 14);

    g.add_edge(1, 0);
    g.set_edge_value(1, 0, 7);

    g.add_edge(1, 2);
    g.set_edge_value(1, 2, 10);

    g.add_edge(1, 3);
    g.set_edge_value(1, 3, 15);

    g.add_edge(2, 0);
    g.set_edge_value(2, 0, 9);

    g.add_edge(2, 1);
    g.set_edge_value(2, 1, 10);

    g.add_edge(2, 3);
    g.set_edge_value(2, 3, 11);

    g.add_edge(2, 5);
    g.set_edge_value(2, 5, 2);

    g.add_edge(3, 1);
    g.set_edge_value(3, 1, 15);

    g.add_edge(3, 2);
    g.set_edge_value(3, 2, 11);

    g.add_edge(3, 4);
    g.set_edge_value(3, 4, 6);

    g.add_edge(4, 3);
    g.set_edge_value(4, 3, 6);

    g.add_edge(4, 5);
    g.set_edge_value(4, 5, 9);

    g.add_edge(5, 0);
    g.set_edge_value(5, 0, 14);

    g.add_edge(5, 2);
    g.set_edge_value(5, 2, 2);

    g.add_edge(5, 4);
    g.set_edge_value(5, 4, 9);

    vector<double> path;
    ShortestPath dij_path(g);
    dij_path.short_path(0, 5, path, g);

    cout << path.size() << endl;
    cout << dij_path.distance.size() << endl;

    for(unsigned int i=0; i<dij_path.distance.size(); i++)
    {
	cout << dij_path.distance[i] << ' ';
    }
    cout << endl;
}

// Constructs a hex board with given dimentions 
HexBoard::HexBoard(int dim)
{
    // Need to construct a board with m X m
    dimention = dim;

    //vectors to store blue and red vertices.
    blueVertices.resize(dim*dim);
    redVertices.resize(dim*dim);

    // Fill with 0s. 1 represents there's a vertex of given color 
    // owned by that player.
    // 0 represents a '.' (empty location)
    fill(blueVertices.begin(), blueVertices.end(), 0);
    fill(redVertices.begin(), redVertices.end(), 0);
}

// Prints hex board with current configuration
void HexBoard::print_board()
{
    // This is the max length of the board in the console print representation
    int length = (2*dimention)+1;

    // Header print A, B, C, D, E, ....
    // Ascii value of 'A'
    int alpha = 65;

    for(int i=0; i<length; i++)
    {
	if(i == 0)
	{
	    cout << ' ';
	    cout << ' ';
	}
	else if(i<=dimention)
	{
	    cout << static_cast<char>(alpha+i-1);
	    cout << ' ';
	}
	else
	{
	    cout << ' ';
	    cout << ' ';
	}
    }
    cout << endl;


    // Now print a number corresponding to that column
    // and print . or X or O according to the board
    int i;
    int j;
    for(i=dimention, j=1; i>0; i--, j++)
    {
	// First print number in the column after some spaces
	for(int tmp=0; tmp<(j-1); tmp++)
	{
	    cout << ' ';
	    cout << ' ';
	}

	// Backspace sometimes, to get that hex feel.
	for(int tmp=0; tmp<j-1; tmp++)
	{
	    cout << '\b';
	}

	// Extra backspace for board of length >= 10
	if(j>=10)
	{
	    cout << '\b';
	}

	cout << j;
	cout << ' ';

	for(int tmp=0; tmp<dimention; tmp++)
	{
	    //cout << ' ';

	    // j-1 th row of vector
	    if(redVertices[((j-1)*dimention)+tmp])
	    {
		cout << 'X';
		cout << ' ';
	    }
	    else if(blueVertices[((j-1)*dimention)+tmp])
	    {
		cout << 'O';
		cout << ' ';
	    }
	    else
	    {
		cout << '.';
		cout << ' ';
	    }
	}

	cout << j;

	for(int tmp=0; tmp<(dimention-1); tmp++)
	{
	    cout << ' ';
	    cout << ' ';
	}

	cout << endl;

    }

    //cout << endl;

    // Footer print A, B, C, D, E, ....
    alpha = 65;

    for(int i=0; i<length; i++)
    {
	if(i < dimention+1)
	{
	    cout << ' ';
	    //cout << ' ';
	}
	else if(i<(length))
	{
	    cout << static_cast<char>(alpha+i-1-dimention);
	    cout << ' ';
	}
	else
	{
	    cout << ' ';
	    cout << ' ';
	}
    }
    cout << '\n' << endl;
}

// Validates input and changes the board 
// or returns error
bool HexBoard::take_input(pair<int, int> p, int player, Graph& g, string str)
{

    if((p.second < 65) || (p.second)>(65+dimention-1))
    {
	cout << "Move (" << p.first << static_cast<char>(p.second) << ") ERROR: Invalid 2nd coordinate" << endl;
	cout << '\n' << endl;
	return false;
    }

    if((p.first < 1) || p.first > (1+dimention-1))
    {
	cout << "Move (" << p.first << static_cast<char>(p.second) << ") ERROR: Invalid 1st coordinate" << endl;
	cout << '\n' << endl;
	return false;
    }

    //Check if it's already occupied
    if (blueVertices[((dimention*(p.first - 1))+(p.second - 65))])
    {
	cout << "Move " << str << " ERROR: Already occupied by blue player/ player 0";
	cout << '\n' << endl;
	return false;
    }

    if (redVertices[((dimention*(p.first - 1))+(p.second - 65))])
    {
	cout << "Move " << str << " ERROR: Already occupied by red player/ player 1";
	cout << '\n' << endl;
	return false;
    }

    if(player == 0)
    {
	blueVertices[((dimention*(p.first - 1))+(p.second - 65))] = 1;
	cout << "Move " << str << " SUCCESS" << endl;
	cout << '\n' << endl;
	moveNumber++;

	// Get all possible neighours and see if they are already occupied
	// If occupied, and there's no edge between them in the graph g,
	// add edge.
	vector<pair<int, int> > neighbours = get_neighbours(p);
	for(int i=0; i<neighbours.size(); i++)
	{
	    int dstVertex = Helper::xy_to_linear(neighbours[i], dimention);
	    int srcVertex = Helper::xy_to_linear(p, dimention);
	    // If neighbour position was occupied and
	    // graph edge, didn't exist
	    if(blueVertices[dstVertex] == 1)
	    {
		// Add edge to neighbours
		if(!g.is_adjacent(srcVertex, dstVertex))
		{
		    g.add_edge(srcVertex, dstVertex);
		    g.set_edge_value(srcVertex, dstVertex, 1.0);

		    g.add_edge(dstVertex, srcVertex);
		    g.set_edge_value(dstVertex, srcVertex, 1.0);
		}
	    }
	}
	return true;
    }

    if(player == 1)
    {
	redVertices[((dimention*(p.first - 1))+(p.second - 65))] = 1;
	cout << "Move " << str << " SUCCESS" << endl;
	cout << '\n' << endl;
	moveNumber++;

	// Get all possible neighours and see if they are already occupied
	// If occupied, and there's no edge between them in the graph g,
	// add edge.
	vector<pair<int, int> > neighbours = get_neighbours(p);
	for(int i=0; i<neighbours.size(); i++)
	{
	    int dstVertex = Helper::xy_to_linear(neighbours[i], dimention);
	    int srcVertex = Helper::xy_to_linear(p, dimention);
	    // If neighbour position was occupied and
	    // graph edge, didn't exist
	    if(redVertices[dstVertex] == 1)
	    {
		// Add edge to neighbours
		if(!g.is_adjacent(srcVertex, dstVertex))
		{
		    g.add_edge(srcVertex, dstVertex);
		    g.set_edge_value(srcVertex, dstVertex, 1.0);

		    g.add_edge(dstVertex, srcVertex);
		    g.set_edge_value(dstVertex, srcVertex, 1.0);
		}
	    }
	}
	return true;
    }

}

// Returns a vector of xy coordinates neighbours of current node
// This first locates the position of the node among corners, edges, rest
// of the board.
vector<pair<int, int> > HexBoard::get_neighbours(const pair<int, int> p)
{
    vector<pair<int, int> > vec;
    // Position of the node
    // 1 - Corner
    // 2 - Edge but not in the corner
    // 3 - Everything else
    int pos = 0;

    // Determine if its in the middle, or in one of the 4 corners
    // or on the edges

    // Code has lot of 1s and 65s. They represent ascii values of '1' and 'A'.

    // Corner : Top left
    if(p.first-1 == 0 && (p.second-65 == 0))
    {
	pos = 1;
	vec.resize(2);
	// Fill with neighbours
	vec[0].first = 1;
	vec[0].second = 65+1;

	vec[1].first = 1+1;
	vec[1].second = 65;

	return vec;
    }

    // Corner: Top right
    if(p.first-1 == 0 && (p.second-65 == (dimention-1)))
    {
	pos = 1;
	vec.resize(3);
	//
	// Fill with neighbours
	vec[0].first = 1;
	vec[0].second = 65+(dimention-2);

	vec[1].first = 1+1;
	vec[1].second = 65+(dimention-1);

	vec[2].first = 1+1;
	vec[2].second = 65+(dimention-2);

	return vec;
    }

    // Corner: Bottom right
    if(p.first-1 == (dimention-1) && (p.second-65 == (dimention-1)))
    {
	pos = 1;
	vec.resize(2);
	//
	// Fill with neighbours
	vec[0].first = 1+(dimention-2);
	vec[0].second = 65+(dimention-1);

	vec[1].first = 1+(dimention-1);
	vec[1].second = 65+(dimention-2);

	return vec;
    }

    // Corner: Bottom left
    if(p.first-1 == (dimention-1) && (p.second-65 == 0))
    {
	pos = 1;
	vec.resize(3);
	//
	// Fill with neighbours
	vec[0].first = 1+(dimention-2);
	vec[0].second = 65;

	vec[1].first = 1+(dimention-2);
	vec[1].second = 65+1;

	vec[2].first = 1+(dimention-1);
	vec[2].second = 65+1;

	return vec;
    }

    // Edge: North edge 
    if(p.first-1 == 0)
    {
	pos = 2;
	vec.resize(4);

	//Fill with neighbours
	vec[0].first = p.first;
	vec[0].second = p.second-1;

	vec[1].first = p.first;
	vec[1].second = p.second+1;

	vec[2].first = p.first+1;
	vec[2].second = p.second-1;

	vec[3].first = p.first+1;
	vec[3].second = p.second;

	return vec;
    }

    // Edge: South edge 
    if(p.first-1 == (dimention-1))
    {
	pos = 2;
	vec.resize(4);

	//Fill with neighbours
	vec[0].first = p.first;
	vec[0].second = p.second-1;

	vec[1].first = p.first;
	vec[1].second = p.second+1;

	vec[2].first = p.first-1;
	vec[2].second = p.second+1;

	vec[3].first = p.first-1;
	vec[3].second = p.second;

	return vec;
    }

    // Edge: East edge 
    if(p.second-65 == (dimention-1))
    {
	pos = 2;
	vec.resize(4);

	//Fill with neighbours
	vec[0].first = p.first-1;
	vec[0].second = p.second;

	vec[1].first = p.first+1;
	vec[1].second = p.second;

	vec[2].first = p.first;
	vec[2].second = p.second-1;

	vec[3].first = p.first+1;
	vec[3].second = p.second-1;

	return vec;
    }

    // Edge: West edge
    if(p.second-65 == 0)
    {
	pos = 2;
	vec.resize(4);

	//Fill with neighbours
	vec[0].first = p.first-1;
	vec[0].second = p.second;

	vec[1].first = p.first+1;
	vec[1].second = p.second;

	vec[2].first = p.first;
	vec[2].second = p.second+1;

	vec[3].first = p.first-1;
	vec[3].second = p.second+1;

	return vec;
    }

    // Somewhere in the middle: Not on the edges, corners
    pos = 3;
    vec.resize(6);

    //Fill with neighbours
    vec[0].first = p.first;
    vec[0].second = p.second-1;

    vec[1].first = p.first;
    vec[1].second = p.second+1;

    vec[2].first = p.first-1;
    vec[2].second = p.second;

    vec[3].first = p.first-1;
    vec[3].second = p.second+1;

    vec[4].first = p.first+1;
    vec[4].second = p.second-1;

    vec[5].first = p.first+1;
    vec[5].second = p.second;

    return vec;
}

// Performs Dijkstra to see if path exists between virtual vertices
// and returns true or false accordingly
bool HexBoard::is_win(int player, Graph& g)
{
    // Find if path exists between 2 virtual vertices.
    int srcVetex = g.get_vertex_count()-2;
    int dstVetex = g.get_vertex_count()-1;

    // Perform Dijkstra on graph g
    vector<double> path;
    ShortestPath dij_path(g);
    bool ret = dij_path.short_path(srcVetex, dstVetex, path, g);

    if(!ret)
    {
	return false;
    }

    if(path.empty())
    {
	return false;
    }

    // If a path exists, parent should be some valid vertex
    if(path[path.size()-1] == -1)
    {
	return false;
    }

    /*
       if(dij_path.distance[dij_path.distance.size()-1] == numeric_limits<double>::max())
       {
       return false;
       }
       */

    // A valid path existed between the virtual vertices.
    return true;
}

// Transforms hex coordinates to linear
int Helper::xy_to_linear(pair<int, int> p, int dimention)
{
    return ((dimention*(p.first-1))+(p.second-65));
}

// Transforms hex coordinates to linear
pair<int, int> Helper::linear_to_xy(int num, int dimention)
{
    pair<int, int> p;

    int row = num/dimention;
    int column = num%dimention;

    // Transform x coordinate to a number.
    if(column == 0)
    {
	p.first = row;
    }
    else
    {
	p.first = (1+row);
    }

    // Transform y coordinate to a letter.
    if(column == 0)
    {
	p.second = 65+dimention-1;
    }
    else
    {
	p.second = (65+(column-1));
    }

    return p;
}

bool HexBoard::is_valid_computermove(pair<int, int> p)
{
    if((p.second < 65) || (p.second)>(65+dimention-1))
    {
	//cout << "Move (" << p.first << static_cast<char>(p.second) << ") ERROR: Invalid 2nd coordinate" << endl;
	//cout << '\n' << endl;
	return false;
    }

    if((p.first < 1) || p.first > (1+dimention-1))
    {
	//cout << "Move (" << p.first << static_cast<char>(p.second) << ") ERROR: Invalid 1st coordinate" << endl;
	//cout << '\n' << endl;
	return false;
    }

    //Check if it's already occupied
    if (blueVertices[((dimention*(p.first - 1))+(p.second - 65))])
    {
	//cout << "Move " << str << " ERROR: Already occupied by blue player/ player 0";
	//cout << '\n' << endl;
	return false;
    }

    if (redVertices[((dimention*(p.first - 1))+(p.second - 65))])
    {
	//cout << "Move " << str << " ERROR: Already occupied by red player/ player 1";
	//cout << '\n' << endl;
	return false;
    }

    return true;
}

int main()
{
    // Test dijkstra

    /*
       LocalTesting test;
       test.Test();
       return 0;
       */

    srand(time(NULL));
    int dimention = 4;

    cout << "Enter HexBoard side length:";
    cin >> dimention;

    if(dimention<2 || dimention>26)
    {
	cout << "\nInvalid dimention, it should be 2<=dimention<=26. Exiting the game" << endl;
	return -1;
    }

    cout << "\nCreating a hexboard of size" << dimention << " X " << dimention << endl;

    HexBoard hex(dimention);
    hex.moveNumber = 0;

    //Create 2 graphs each of size (dimention*dimention)+2
    //those last 2 additional vertices are for virtual nodes
    //Creating 2 separate graphs each for players 0(Blue) and 1(Red)
    int vertices = (dimention*dimention)+2;
    Graph g0(vertices);
    Graph g1(vertices);

    // Now, connect virtual nodes with corresponding nodes
    // For g0, WEST virtual vertex is vertex[vertices-2]
    // EAST virtual vertex is vertex[vertices-1]

    // For g1, NORTH virtual vertex is vertex[vertices-2]
    // SOUTH virual vertex is vertex[vertices-1]

    // Connecting WEST virtual vertex with 1A, 2A, 3A, 4A, ....
    for(int i=0; i<dimention; i++)
    {
	// Undirected graph, so adding it twice
	g0.add_edge((g0.vertices)-2, (i*dimention));
	g0.add_edge((i*dimention), (g0.vertices)-2);

	// Setting edge_values 1 for all.
	g0.set_edge_value((g0.vertices)-2, (i*dimention), 1.0);
	g0.set_edge_value((i*dimention), (g0.vertices)-2, 1.0);
    }

    // Connecting EAST virtual vertex with 1G, 2G, 3G, 4G, ....(if it's a 7x7 board)
    for(int i=0; i<dimention; i++)
    {
	// Undirected graph, so adding it twice
	g0.add_edge((g0.vertices)-1, (i*dimention+(dimention-1)));
	g0.add_edge((i*dimention+(dimention-1)), (g0.vertices)-1);

	// Setting edge_values 1 for all.
	g0.set_edge_value((g0.vertices)-1, (i*dimention+(dimention-1)), 1.0);
	g0.set_edge_value((i*dimention+(dimention-1)), (g0.vertices)-1, 1.0);
    }

    // Connecting NORTH virtual vertex with 1A, 1B, 1C, 1D, ..etc.
    for(int i=0; i<dimention; i++)
    {
	// Undirected graph, so adding it twice
	g1.add_edge((g1.vertices)-2, (i));
	g1.add_edge((i), (g1.vertices)-2);

	// Setting edge_values 1 for all.
	g1.set_edge_value((g1.vertices)-2, (i), 1.0);
	g1.set_edge_value((i), (g1.vertices)-2, 1.0);
    }

    // Connecting SOUTH virtual vertex with 7A, 7B, 7C, 7D, ....(if it's a 7x7 board)
    for(int i=0; i<dimention; i++)
    {
	// Undirected graph, so adding it twice
	g1.add_edge((g1.vertices)-1, (dimention*(dimention-1)+i));
	g1.add_edge((dimention*(dimention-1)+i), (g1.vertices)-1);

	// Setting edge_values 1 for all.
	g1.set_edge_value((g1.vertices)-1, (dimention*(dimention-1)+i), 1.0);
	g1.set_edge_value((dimention*(dimention-1)+i), (g1.vertices)-1, 1.0);
    }

    cout << "Blue player(Player 0) direction is EAST<->WEST. Occupied position is shown with O" << '\n' << endl;
    cout << "Red player(Player 1) direction is NORTH<->SOUTH. Occupied position is shown with X" << '\n' << endl;
    hex.print_board();

    cout << '\n' << "Always enter ROW COLUMN(without space and in capital letters)" << endl;
    cout << "So, row would always be a number and column would be a char" << endl;
    cout << "Example: 5B is correct, but B5 is wrong" << endl;
    cout << '\n' << endl;
    cout << "===================================================================" << endl;
    cout << "Remember that Blue player always starts the game." << '\n' << endl;
    cout << "Game is starting now" << '\n' << endl;
    cout << "===================================================================" << '\n' << endl;
    //cout << "Helper " << Helper::xy_to_linear(string("4D"), 4) << '\n' << endl;
    //cout << "Helper " << Helper::linear_to_xy(15, 4) << '\n' << endl;

    //Main while loop where game is played
    //while nobody won the game
    char ch;
    int isHumanFirst = 1;
    cout << "Human, do you wanna go first? (Y/N) :";
    cin >> ch;
    cout << '\n' << endl;

    if(toupper(ch) == 'Y')
    {
	isHumanFirst = 1;
    }
    else if(toupper(ch) == 'N')
    {
	isHumanFirst = 0;
    }
    else
    {
	cout << "You neither entered Y or N. By default human goes first." << endl;
    }


    while((hex.is_win(0, g0)==false) && (hex.is_win(1, g1)==false))
    {
	string player;
	string color;
	string move;
	pair<int, int> p;

	// Determine which player is playing based on moveNumber.
	// Player 0 if even moveNumber, Player 1 otherwise.
	if(hex.moveNumber%2==0)
	{
	    if(isHumanFirst)
	    {
		player = "Human";
	    }
	    else
	    {
		player = "Computer";
	    }

	    color.assign("Blue");
	}
	else
	{
	    if(isHumanFirst)
	    {
		player = "Computer";
	    }
	    else
	    {
		player = "Human";
	    }

	    color.assign("Red");
	}

	cout << "Player: " << color << "(" << player << ")" << "is playing" << endl;
	cout << "Move number:" << hex.moveNumber << endl;

	if(player == "Human")
	{
	    cout << "Enter move:";
	    cin >> move;
	}
	else
	{
	    cout << "Computer is thinking.." << endl;
	    cout << "Computer is entering move:";

	    int m = 0;

	    // Computer guesses random numbers until it finds a valid move
	    while(true)
	    {
		// Think a random location
		m = (int) (1.0 + (1.0*dimention*dimention*((float) rand()) / RAND_MAX));
		p = Helper::linear_to_xy(m, dimention);

		if(hex.is_valid_computermove(p))
		{
		    break;
		}
	    }

	    cout << p.first << static_cast<char>(p.second) << endl;
	}

	//This is all needed if player is Human
	if(player == "Human")
	{

	    //Convert move to a pair(x,y)
	    //x is row(digit), and y is a letter(A-Z/a-z);
	    const char *str = move.c_str();
	    char *tmp = NULL;
	    long int row = strtol(str, &tmp, 10);
	    if(row == 0)
	    {
		//Invalid move
		cout << "Invalid move:" << move << endl;
		cout << "Invalid row\n" << endl;
		continue;
	    }

	    if(strlen(tmp) != 1)
	    {
		cout << "Invalid move:" << move << endl;
		cout << "Invalid column\n" << endl;
		continue;
	    }


	    p = make_pair(row, toupper(tmp[0]));
	}

	// Take input move and process it.
	// Corresponding graphs are passed along with player number.
	if(color == "Blue")
	{
	    hex.take_input(p, 0, g0, move);
	    hex.print_board();
	}
	else
	{
	    hex.take_input(p, 1, g1, move);
	    hex.print_board();
	}
    }

    // While loop is broken. So, someone won the game.
    if(hex.is_win(0, g0))
    {

	string player;

	if(isHumanFirst)
	{
	    player = "Human";
	}
	else
	{
	    player = "Computer";
	}

	cout << '\n' << "PLAYER BLUE (" <<  player << ") just won the game" << endl;
    }
    if(hex.is_win(1, g1))
    {
	string player;

	if(isHumanFirst)
	{
	    player = "Computer";
	}
	else
	{
	    player = "Human";
	}

	cout << '\n' << "PLAYER RED (" << player << ") just won the game" << endl;
    }

    cout << "\nExiting the game" << endl;

    // Simple tests

    /*
       HexBoard hex(4);
       hex.print_board();
       Helper helper;
       cout << "Helper " << helper.xy_to_linear(string("4D"), 4) << '\n' << endl;
       cout << "Helper " << helper.linear_to_xy(15, 4) << '\n' << endl;
       hex.take_input("1A", 0);
       hex.print_board();
       hex.take_input("2B", 1);
       hex.print_board();
       hex.take_input("4D", 1);
       hex.print_board();
       */
    return 0;
}
