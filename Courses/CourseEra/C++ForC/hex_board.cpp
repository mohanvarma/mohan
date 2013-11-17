#include "hex_board.h"

// To, know more about what each of the following methods does,
// refer to 'hex_board.h' file.
//

Graph::Graph(int x)
{
	vertices = x;
	edges = 0;
	edge_lists.resize(x);
}

int Graph::get_vertex_count()
{
	return vertices;
}

int Graph::get_edge_count()
{
	return edges;
}

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

void Graph::neighbours(int x, vector<int>& list)
{
	list.clear();

	// Add all the members of edge_lists[x] to the list vector
	for(unsigned int i = 0; i < edge_lists[x].size(); i++)
	{
		list.push_back(edge_lists[x][i].vertex);
	}
}

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

void Graph::delete_edge(int x, int y)
{
    //Iterator of vector_of_pairs
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

int Graph::get_edge_value(int x, int y)
{
    	// Itereate all the members of edge_lists[x] and return
	// the edge_weight from the matched pair
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

void Graph::set_edge_value(int x, int y, double val)
{
    	// Itereate all the members of edge_lists[x] and set 
	// the edge_weight for the matched pair
	for(unsigned int j = 0; j < edge_lists[x].size(); j++)
	{
		if(edge_lists[x][j].vertex == y)
		{
			edge_lists[x][j].val = val;
		}
	}
}

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

void ShortestPath::short_path(int x, int y, vector<double>& path,
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
			int weight = edge_list[vertex][i].val;

			// If distance travelled to destination through
			// 'vertex' is better than direct distance
			// update it
			if(distance[neighbour] > (distance[vertex]+weight))
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

	while(destination != x)
	{
		destination = parent[destination];
		path.push_back(destination);
	}
}

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

	blueVertices.resize(dim*dim);
	redVertices.resize(dim*dim);

	// Fill with 0s. 1 represents there's a vertex of given color 
	// owned by that player
	fill(blueVertices.begin(), blueVertices.end(), 0);
	fill(redVertices.begin(), redVertices.end(), 0);
}

// Prints hex board with current configuration
void HexBoard::print_board()
{
	// This is the max length of the board in the console print representation
	int length = (2*dimention)+1;

	// Header print A, B, C, D, E, ....
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
	cout << '\n' << endl;


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

	    cout << '\n' << endl;

	}

	//cout << endl;

	// Footer print A, B, C, D, E, ....
	alpha = 65;

	for(int i=0; i<length; i++)
	{
	    if(i < dimention+1)
	    {
		cout << ' ';
		cout << ' ';
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
bool HexBoard::take_input(string str, int player)
{

    if(str.size()!=2)
    {
	cout << "Move " << str << " ERROR: Size of the entered coordinates string is not equal to 2" << endl;
	cout << '\n' << endl;
	return false;
    }

    if((static_cast<int>(str[1])<65) || (static_cast<int>(str[1])>(65+dimention-1)))
    {
	cout << "Move " << str << " ERROR: Invalid 2nd coordinate" << endl;
	cout << '\n' << endl;
	return false;
    }

    if(static_cast<int>(str[0])<49 || static_cast<int>(str[0])>(49+dimention-1))
    {
	cout << "Move " << str << " ERROR: Invalid 1st coordinate" << endl;
	cout << '\n' << endl;
	return false;
    }

    //Check if it's already occupied
    if (blueVertices[((dimention*(static_cast<int>(str[0])-49))+(static_cast<int>(str[1])-65))])
    {
	cout << "Move " << str << " ERROR: Already occupied by blue player/ player 0";
	cout << '\n' << endl;
	return false;
    }

    if (redVertices[((dimention*(static_cast<int>(str[0])-49))+(static_cast<int>(str[1])-65))])
    {
	cout << "Move " << str << " ERROR: Already occupied by red player/ player 1";
	cout << '\n' << endl;
	return false;
    }

    if(player == 0)
    {
	blueVertices[((dimention*(static_cast<int>(str[0])-49))+(static_cast<int>(str[1])-65))] = 1;
	cout << "Move " << str << " SUCCESS" << endl;
	cout << '\n' << endl;
	return true;
    }

    if(player == 1)
    {
	redVertices[((dimention*(static_cast<int>(str[0])-49))+(static_cast<int>(str[1])-65))] = 1;
	cout << "Move " << str << " SUCCESS" << endl;
	cout << '\n' << endl;
	return true;
    }

}

// Returns a vector of xy coordinates neighbours of current node
vector<string> HexBoard::get_neighbours(string str)
{
    vector<string> vec;
    int pos = 0;

    // Determine if its in the middle, or in one of the 4 corners
    // or on the edges
    
    // Corner : Top left
    if(static_cast<int>(str[0])-49 == 0 && (static_cast<int>(str[1])-65 == 0))
    {
	pos = 1;
	vec.resize(3);
    }

    // Corner: Top right
    if(static_cast<int>(str[0])-49 == 0 && (static_cast<int>(str[1])-65 == (dimention-1)))
    {
	pos = 1;
	vec.resize(3);
    }

    // Corner: Bottom right
    if(static_cast<int>(str[0])-49 == (dimention-1) && (static_cast<int>(str[1])-65 == (dimention-1)))
    {
	pos = 1;
	vec.resize(3);
    }

    // Corner: Bottom left
    if(static_cast<int>(str[0])-49 == (dimention-1) && (static_cast<int>(str[1])-65 == 0))
    {
	pos = 1;
	vec.resize(3);
    }

}

// Transforms hex coordinates to linear
int Helper::xy_to_linear(string str, int dimention)
{
    return ((dimention*(static_cast<int>(str[0])-49))+(static_cast<int>(str[1])-65));
}

// Transforms hex coordinates to linear
string Helper::linear_to_xy(int num, int dimention)
{
    string str;
    str.resize(2);

    int row = num/dimention;
    int column = num%dimention;

    str[0] = static_cast<char>(49+row);
    str[1] = static_cast<char>(65+column);

    return str;
}

int main()
{
	// Test dijkstra
	/*
	LocalTesting test;
	test.Test();
	return 0;
	*/

	cout << "Blue player(Player 0) direction is EAST<->WEST" << '\n' << endl;
	cout << "Red player(Player 1) direction is NORTH<->SOUTH" << '\n' << endl;
	cout << "Always enter row column(without spaces)" << endl;
	cout << "So, row would always be a number and column would be a char" << endl;
	cout << "Example: 5B is correct, but B5 is wrong" << endl;
	cout << '\n' << endl;

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
	return 0;
}
