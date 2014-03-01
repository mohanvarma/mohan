# transpose of a given graph
def transpose(graph):
        trans = {}
        for src in graph.keys():
                for dst in graph[src]:
                        # If already present, append
                        if dst in trans.keys():
                                trans[dst].append(src)
                        else:
                                trans[dst] = []
                                trans[dst].append(src)
        return trans
graph = {}
graph[1] = [2,3]
graph[2] = [1]
graph[3] = [1,2]
print graph
trans = transpose(graph)
print trans

