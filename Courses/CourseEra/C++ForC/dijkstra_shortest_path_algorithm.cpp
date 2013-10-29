#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

const int VERTICES = 50;

// typedef to store vector of( vector of (pairs))
// pair contains node and corresponding edge weight
// So, each vertex has an edge_list, each entry in the edge_list has a pair with first value 
// containing the vertex index and second value containing weight of the edge
typedef vector<vector<pair<int, int> > > vector_of_vector_of_pairs;

typedef vector<pair<int, int> > vector_of_pairs;

class Graph
{
	public:

		int edges; // No. of edges
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
		void set_edge_value(int x, int y, int val);

};

Graph::Graph(int x)
{
	vertices = x;
	edges = 0;
	edge_lists.resize(x);
	/*
	for(int i=0; i<edge_lists.size(); i++)
	{
	    edge_lists[i].resize(0);
	}
	*/
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
	for(int i = 0; i < edge_lists.size(); i++)
	{
	    for(int j = 0; j < edge_lists[i].size(); j++)
	    {
		if(edge_lists[i][j].first == y)
		{
		    return true;
		}
	    }
	}

	return false;
}	

void Graph::neighbours(int x, vector<int>& list)
{
	list.clear();

	for(int i = 0; i < edge_lists[x].size(); i++)
	{
		list.push_back(edge_lists[x][i].first);
	}
}

void Graph::add_edge(int x, int y)
{
	//add_edge with value -1
	edge_lists[x].push_back(make_pair(y, -1));

	//Increment the edge count
	edges++;
}

void Graph::delete_edge(int x, int y)
{
    	/*
	//Iterator of vector_of_pairs
	vector_of_pairs::Iterator ite;
	for(ite = edge_lists[x].begin(); ite != edge_lists.end(); ite++)
	{
		if(ite->first == y)
		{
			ite = edge_lists[x].erase(ite);

			//Decrement the edge count
			edges--;

			return;
		}	
	}
	*/

}

int Graph::get_edge_value(int x, int y)
{
    	for(int i = 0; i < edge_lists.size(); i++)
	{
	    for(int j = 0; j < edge_lists[i].size(); j++)
	    {
		if(edge_lists[i][j].first == y)
		{
			return edge_lists[i][j].second;
		}
	    }
	}
}

void Graph::set_edge_value(int x, int y, int val)
{
	for(int i = 0; i < edge_lists.size(); i++)
	{
	    for(int j = 0; j < edge_lists[i].size(); j++)
	    {
		if(edge_lists[i][j].first == y)
		{
			edge_lists[i][j].second = val;
		}
	    }
	}
}

class ComparePairs
{
    public:
	int operator() (const pair<int, int>& p1, const pair<int, int> &p2)
	{
	    return p1.second > p2.second;
	}
};

class ShortestPath
{
	public:

		vector<int> path; // vector representing the sequence of vertices(path)
		int path_length; // path cost

		vector<int> distance; // vector of distances
		vector<int> parent; // vector of parent nodes. parent[i] gives the parent of i
							// This vector will be used to backtrack from destination to construct path

		// Constructor of ShortestPath Class
		// Graph class instance is passed as a reference.
		ShortestPath(Graph& g);

		// Returns(modifies the passed reference) sequence of vertices
		// in the path from x to y
		void short_path(int x, int y, vector<int>& path,
				Graph& g);

		// Returns path size
		int path_size(int x, int y);

		void short_path_test(int source, int destination, vector<int>& path,
		Graph& g);
};

ShortestPath::ShortestPath(Graph& g)
{
    	vector_of_vector_of_pairs edge_lists = g.edge_lists;
	distance.resize(edge_lists.size());
	parent.resize(edge_lists.size());

	for(int i = 0; i < distance.size(); i++)
	{
		// Closest thing to infinity
		// max possible value of int
		distance[i] = numeric_limits<int>::max();

		// Initialize parent vector
		parent[i] = -1;
	}
}

void ShortestPath::short_path(int x, int y, vector<int>& path,
		Graph& g)
{
    	vector_of_vector_of_pairs edge_list = g.edge_lists;

	// Using priority queue from STL
	// It returns least value by default, so modifying it 
	// by using Comparator class for returning max value
	priority_queue<pair<int,int>, vector<pair<int,int> >, ComparePairs> pq;

	distance[x] = 0;

	//Push pair<x, edge value> to the pq
	pq.push(make_pair(x, distance[x]));

	// while pq is not empty
	// Dijkstra's algorithm.
	while(!pq.empty())
	{
		// Get the least weight edge
		int vertex = pq.top().first;

		//If vertex itself is the required destination, stop the process
		if(vertex == y)
		{
			break;
		}

		// Else, remove this vertex from pq and add all neighbouring edges to pq
		pq.pop();

		for(int i=0; i < edge_list[vertex].size(); i++)
		{
			int neighbour = edge_list[vertex][i].first;
			int weight = edge_list[vertex][i].second;

			// If distance travelled to destination through
			// 'vertex' is better than direct distance
			// update it
			if(distance[neighbour] > (distance[vertex]+weight))
			{
				distance[neighbour] = distance[vertex]+weight;
				parent[neighbour] = vertex;

				// Push neighbour and it's updated distace to pq
				pq.push(make_pair(neighbour, distance[neighbour]));
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

void ShortestPath::short_path_test(int x, int y, vector<int>& path,
		Graph& g)
{
    vector_of_vector_of_pairs edge_list = g.edge_lists;

    // Using priority queue from STL
    // It returns least value by default, so modifying it 
    // by using Comparator class for returning max value
    priority_queue<pair<int,int>, vector<pair<int,int> >, ComparePairs> pq;
    
    distance[x] = 0;
    
    pq.push(make_pair(x, distance[x]));

    while(!pq.empty())
    {
	int vertex = pq.top().first;

	if(vertex == y)
	{
	    break;
	}

	pq.pop();

	for(int i=0; i < edge_list[vertex].size(); i++)
	{
	    int v = edge_list[vertex][i].first;
	    int w = edge_list[vertex][i].second;
	    if(distance[v] > distance[vertex]+w)
	    {
		distance[v] = distance[vertex]+w;
		parent[v] = vertex;
		pq.push(make_pair(v,distance[v]));
	    }
	}
    }

    path.clear();

    int p = y;
    path.push_back(y);

    while(p != x)
    {
	p = parent[p];
	path.push_back(p);
    }
}


int main()
{
    //Sample test_case
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

    vector<int> path;
    ShortestPath dij_path(g);
    dij_path.short_path_test(0, 3, path, g);
}
