// prims_algo.cpp - This file contains methods for creating 
// and processing a graph data type and finally finding the 
// minimum spanning tree of a given graph
//

// To, know more about what each of the following methods does,
// refer to 'prims_algo.h' file.
//

#include "prims_algo.h"

// Graph constructor
Graph::Graph(int x)
{
	vertices = x;
	edges = 0;
	edgeLists.resize(x);
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
	for(unsigned int j = 0; j < edgeLists[x].size(); j++)
	{
		if(edgeLists[x][j].first == y)
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

	// Add all the members of edgeLists[x] to the list vector
	for(unsigned int i = 0; i < edgeLists[x].size(); i++)
	{
		list.push_back(edgeLists[x][i].first);
	}
}

// Adds an edge x<->y to the graph
void Graph::add_edge(int x, int y)
{
	//add_edge with value -1
	edgeLists[x].push_back(make_pair(y, -1));

	//Increment the edge count
	edges++;
}

// Deletes an edge x<->y from the graph
void Graph::delete_edge(int x, int y)
{
	//Iterator of vector_of_pairs
	vector_of_pairs::iterator ite;
	for(ite = edgeLists[x].begin(); ite != edgeLists[x].end(); ite++)
	{
		if(ite->first == y)
		{
			ite = edgeLists[x].erase(ite);
			//Decrement the edge count
			edges--;
			return;
		}        
	}
}

// Gets the value associated with edge x<->y
double Graph::get_edge_value(int x, int y)
{
	// Itereate all the members of edgeLists[x] and return
	// the edge_weight from the matched pair
	for(unsigned int j = 0; j < edgeLists[x].size(); j++)
	{
		if(edgeLists[x][j].first == y)
		{
			return edgeLists[x][j].second;
		}
	}

	// For a correctly constructed graph, code should never reach here
	// But just in case, we return the infinity value
	return numeric_limits<double>::max();
}

// Sets the value associated with edge x<->y
void Graph::set_edge_value(int x, int y, double val)
{
	// Itereate all the members of edgeLists[x] and set
	// the edge_weight for the matched pair
	for(unsigned int j = 0; j < edgeLists[x].size(); j++)
	{
		if(edgeLists[x][j].first == y)
		{
			edgeLists[x][j].second = val;
		}
	}
}

// Computes MST of the given graph
void Graph::compute_mst()
{
	// Create PrimsAlgo object
	PrimsAlgo prims;

	// Compute MST of present graph
	// *this gives current object
	prims.mst_of_graph(*this);

	cout << "Total MST Cost: " << prims.mstCost << endl;

	// From all the mstEdgeLists, add the edgeweights
	for(int i=0; i<prims.mstVertices.size(); i++)
	{
		if(prims.mstEdgeLists[i].size() > 0)
		{
			for(int j=0; j<prims.mstEdgeLists[i].size(); j++)
			{
				cout << i << " " << prims.mstEdgeLists[i][j].first 
						<< " " << prims.mstEdgeLists[i][j].second << endl;
				cout << prims.mstEdgeLists[i][j].first << " " << i
						<< " " << prims.mstEdgeLists[i][j].second << endl;
				//sum += prims.mstEdgeLists[i][j].second;
			}
		}
	}
}

// Computes minimum spanning tree of the given graph
void PrimsAlgo::mst_of_graph(Graph& g)
{
	int vertexCount = g.get_vertex_count();

	mstEdgeLists.resize(vertexCount);
	mstVertices.clear();
	mstCost = 0.0;

	// No vertices are added
	// Choose 0 arbitrarily.
	int currentVertex = 0;

	// Add this vertex to the MST vertices
	mstVertices.push_back(currentVertex);

	// Declare a STL priority queue containing MstEdges
	// pq returns an edge containing least edge value
	//
	// 'ComparePairs' compares 2 MstEdges and returns 
	// an edge with min edge value
	priority_queue<MstEdge, vector<MstEdge >, CompareEdges> pq;

	// Push all the neighbouring edges to pq
	for(int i=0; i<g.edgeLists[currentVertex].size(); i++)
	{
		// Create a MstEdge with src vertex currentVertex
		// and destination vertex, edge weight taken from edgeLists
		MstEdge edge;
		edge.src = currentVertex;
		edge.dst = g.edgeLists[currentVertex][i].first;
		edge.val = g.edgeLists[currentVertex][i].second;

		// Push this edge to pq
		pq.push(edge);
	}


	// While mstVertices set is not equal to total vertices of graph
	while(mstVertices.size() < vertexCount)
	{
		int vertex1 = pq.top().src;
		int vertex2 = pq.top().dst;
		double edgeWeight = pq.top().val;

		// Pop the least weight edge from pq
		pq.pop();

		// If vertex1 is in the mstVertices set and vertex2 is not
		// add vertex2 to the set 
		if ((find(mstVertices.begin(), mstVertices.end(), vertex1)!=mstVertices.end()) &&
				(find(mstVertices.begin(), mstVertices.end(), vertex2)==mstVertices.end()))
		{
			// Print edge and corresponding value
			//cout << left << setfill(' ') << setw(4) << vertex1 << " "; 
			//cout << left << setfill(' ') << setw(4) << vertex2 << " ";
			//cout << left << setfill(' ') << setw(6) << edgeWeight << " " << endl;

			// Undirected graph, so print each edge twice
			// similar to input file
			//cout << left << setfill(' ') << setw(4) << vertex2 << " ";
			//cout << left << setfill(' ') << setw(4) << vertex1 << " ";
			//cout << left << setfill(' ') << setw(6) << edgeWeight << " " << endl;
			mstCost += edgeWeight;

			// Push vertex2 to the set
			mstVertices.push_back(vertex2);

			// Update edge lists representing MST.
			mstEdgeLists[vertex1].push_back(make_pair(vertex2, edgeWeight));

			// Now, vertex2 is added, so add all the neighbouring edges of 
			// vertex2 to the pq
			for(int i=0; i<g.edgeLists[vertex2].size(); i++)
			{
				// Create edge
				MstEdge edge;
				edge.src = vertex2;
				edge.dst = g.edgeLists[vertex2][i].first;
				edge.val = g.edgeLists[vertex2][i].second;

				// Push it to pq
				pq.push(edge);
			}
		}
	}
}


int main()
{
	int vertices = 0;

	// Two end vertices of an edge
	int edgeV1, edgeV2;

	// Edge value
	double edgeVal;

	// Define an input file stream
	ifstream input( "input_2.txt" );

	// Get the number of vertices
	input >> vertices;

	// Create a graph with given number of vertices
	Graph g(vertices);

	// Input edge edgeV1<->edgeV2 and it's value
	while(input >> edgeV1 >> edgeV2 >> edgeVal)
	{
		g.add_edge(edgeV1, edgeV2);
		g.set_edge_value(edgeV1, edgeV2, edgeVal);
	}

	// Compute MST of the graph G
	g.compute_mst();

	return 0;
}

