''' 
 a   b
 |\  |
   \ |
 "  \"
 c__"d
 |
 "
 e"_f
 \   |
 \   "
 \   g
 \
 \   "
   \ |
    " h
'''

time = 0

def Dfs(Graph):
    for vertex in Graph.keys():
    	if Distances[vertex] == -1:
    	    Dfs_visit(Graph, vertex)

def Dfs_visit(Graph, vertex):
    #print 'vertex', vertex , 'is visited at distance', Distances[vertex] 
    global time
    time = time + 1
    print 'vertex', vertex , 'is visited at time', time
    adj_list = Graph[vertex]
    for v in adj_list:
	#print 'list #', Distances
	if Distances[v] == -1:
	    Distances[v] = Distances[vertex] + 1
	    Dfs_visit(Graph, v)
    time = time + 1
    Finish_times[vertex] = time
    print 'vertex', vertex, 'revisited at time', time

a, b, c, d, e, f, g, h = range(8)

#adj lists
Graph = {
    	a: [c, d],
	b: [d],
	c: [d, e],
	d: [],
	e: [h],
	f: [g],
	g: [h],
	h: []
	}

Finish_times = {}

#initialize distances array with -1
Distances = [-1]*len(Graph)

Dfs(Graph)	
print Finish_times
print sorted(Finish_times.values())
    	



