#include "dijkstra_shortest_path_algo.h"

// To, know more about what each of the following methods does,
// refer to 'dijkstra_shortest_path_algo.h' file.
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
		if(edge_lists[x][j].first == y)
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
	// Could not get this code compiled :( , commenting it for now
	//

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
    	// Itereate all the members of edge_lists[x] and return
	// the edge_weight from the matched pair
	for(unsigned int j = 0; j < edge_lists[x].size(); j++)
	{
		if(edge_lists[x][j].first == y)
		{
			return edge_lists[x][j].second;
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
		if(edge_lists[x][j].first == y)
		{
			edge_lists[x][j].second = val;
		}
	}
}

ShortestPath::ShortestPath(const Graph& g)
{
	vector_of_vector_of_pairs edge_lists = g.edge_lists;
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
	vector_of_vector_of_pairs edge_list = g.edge_lists;

	// Using priority queue from STL
	// It returns least value by default, so modifying it
	// by using Comparator class for returning max value
	priority_queue<pair<int, double>, vector<pair<int, double> >, ComparePairs> pq;

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

		for(unsigned int i=0; i < edge_list[vertex].size(); i++)
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

double GraphGenerate::generate_and_simulate(int vertices, double density, unsigned int simulations)
{
    	// Initialize avg_simulated_distance
	double avg_simulated_distance = 0.0;

	for(unsigned int i=0; i<simulations ; i++)
	{
	    // Create a graph of 50 vertices
	    Graph g(vertices);
	    // This vector stores the shortest distances to corresponding vertices
	    vector<double> distances(vertices);

	    double avg_distance = 0.0;
	    int reachable_vertices = 0;

	    // generate all combinations of x,y
	    for (unsigned int i = 0; i < static_cast<unsigned int>(vertices-1); i++)
	    {
		for (unsigned int j = i + 1; j < static_cast<unsigned int>(vertices); j++)
		{
		    // If the chosen number is < density, pick this edge
		    if ((((double) rand()) / RAND_MAX) < density)
		    {
			// generate a number between 1.0 and 10.0
			double edge_length = 1.0 + ((9.0) * ((double) rand()) / RAND_MAX);

			// Undirected graph, so add 2 edges for each combination
			g.add_edge(i, j);
			g.add_edge(j, i);

			// Set edge values with edge length generated above
			g.set_edge_value(i, j, edge_length);
			g.set_edge_value(j, i, edge_length);
		    }
		}
	    }

	    // For all edges 1<-> [2..49], find the shorted path to that vertex i
	    // and add it to the distances vector
	    for (unsigned int i = 1; i < static_cast<unsigned int>(vertices); i++)
	    {
		vector<double> path;

		// Create ShortestPath object
		ShortestPath dij_path(g);

		// Compute the shortest path to vertex i
		// distance will be updated at dij_path.distances[i]
		dij_path.short_path(0, i, path, g);

		// Copy that distance to local distances vector
		distances.at(i) = dij_path.distance.at(i);
	    }


	    // Find all the reachable vertices(whose distance is not infinity)
	    // and add their distances from 'vertex 1' to avg_distance
	    for(unsigned int i=1; i<distances.size(); i++)
	    {
		// This vertex is reachable
		if(distances.at(i) != numeric_limits<double>::max())
		{
		    // Increment reachable vertex count
		    reachable_vertices++;

		    avg_distance += distances.at(i);
		}
	    }

	    // Divide the sum of distance by no. of reachable vertices
	    avg_distance = avg_distance / reachable_vertices;

	    // Add the avg_distance to avg_simulated_distance
	    avg_simulated_distance +=  avg_distance;
	}

	//Once the simulations are complete, take the avg of all simulations
	avg_simulated_distance = avg_simulated_distance / simulations;

	return avg_simulated_distance;
}

int main()
{
	// This was used to test my classes locally
    	/*
	LocalTesting test;
	test.Test();
	return 0;
	*/

	GraphGenerate graph;

	cout << "Generating graph with density 0.2 and running simulation" << endl;
	// Run 1000 simulation on a graph with 50 vetices and density 0.2
	// Please change the last parameter from 1000 to x if you wanna run those many simulations
	cout << "Avg path length when edge density is 0.2: " << graph.generate_and_simulate(VERTICES, 0.2, 10000) << endl;

	cout << "Generating graph with density 0.4 and running simulation" << endl;
	// Run 1000 simulation on a graph with 50 vetices and density 0.4
	// Please change the last parameter from 1000 to x if you wanna run those many simulations
	cout << "Avg path length when edge density is 0.4: " << graph.generate_and_simulate(VERTICES, 0.4, 10000) << endl;

	return 0;
}

