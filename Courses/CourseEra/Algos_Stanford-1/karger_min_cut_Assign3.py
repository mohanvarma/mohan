import math
import random
import copy
import sys
import time

# This dict will be used to count the frequencies
kargers = {}

class Graph:
    def __init__(self):
        self.edgeList = {}
        self.edgeCount = 0
        self.vertexCount = 0
        
    def add_edge(self, src, dst):
        if src not in self.edgeList.keys():
            self.edgeList[src] = list([])
            self.vertexCount = self.vertexCount+1
            
        self.edgeList[src].append(dst)
        self.edgeCount = self.edgeCount+1

    def process_lists(self, src, dst):
        # Remove self loops
        # replace dst with src in whole dict
        for i in self.edgeList.keys():
            for j in range(len(self.edgeList[i])):
                if self.edgeList[i][j] == dst:
                    self.edgeList[i][j] = src

        for i in self.edgeList.keys():
            k = len(self.edgeList[i])
            while k>0:
                if i == self.edgeList[i][k-1]:
                    del self.edgeList[i][k-1]
                k -= 1

    def contract_edge(self, src, dst):
        # Merging vertices src and dst as 1
        # This includes appending the dst edge list to src,
        # removing self loops
        # removing dst edge list
        # replacing dst with src in the whole dict
        self.edgeList[src].extend(self.edgeList[dst][:])
        del self.edgeList[dst]
        self.process_lists(src, dst)
    
def run_kragers_on_copy(graph):
    # Choose a random edge from the ramaining graph and contract it
    # while at least 2 vertices are remaining
    random.seed(time.time())
    while len(graph.edgeList)>2:
        src = random.choice(graph.edgeList.keys())
        dst = random.choice(graph.edgeList[src])
        graph.contract_edge(src, dst)
    
    # Finally only 2 edges should remain
    assert (len(graph.edgeList) == 2)
    key_list = graph.edgeList.keys()

    # All the remaining edges should be parallel, so degrees should be same
    assert (len(graph.edgeList[key_list[0]]) == len(graph.edgeList[key_list[1]]))

    print 'Cuts:', len(graph.edgeList[key_list[0]])

    # Save in a dict
    try:
        kargers[len(graph.edgeList[key_list[0]])] += 1
    except KeyError:
        kargers[len(graph.edgeList[key_list[0]])] = 1

    return len(graph.edgeList[key_list[0]])

def run_kragers(graph, N):
    # Run kragers algo N times and report best min cut
    best = sys.maxint
    cuts = 0
    while N>0:
        cuts = run_kragers_on_copy(copy.deepcopy(graph))
        if cuts < best:
            best = cuts
        N -= 1
    return best

# read from
def main():
    # file handle
    fp = open("kargerMinCut.txt")

    graph = Graph()
    
    for line in fp.read().splitlines():
        lst = line.split('\t')
        # delete last tab
        lst.pop()
        #print lst
        vertex = lst[0]
        for i in range(1, len(lst)):
            graph.add_edge(int(vertex), int(lst[i]))

    #graph.contract_edge(1, 2)
    #print graph.edgeList
    #graph.contract_edge(3, 1)
    #print graph.edgeList
    vertices = len(graph.edgeList)
    N = int(vertices*vertices*math.log(vertices, 2))

    # Testing it 100 times now, make it N
    print 'Testing', 100, 'times'
    ret = run_kragers(graph, 100)
    print 'Returned', ret

    # sort the dictionary by its keys, descending order
    frequencies = sorted(kargers.items(), key = lambda x: x[1])
    frequencies.reverse()
    print frequencies
            
main()
