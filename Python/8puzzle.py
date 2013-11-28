import copy as c
import heapq as h
no_nodes = 0
path = []
visited = []

class Node:
    def __init__(self,contents,mhtn=0):
        self.contents = contents
        self.mhtn = mhtn
        self.parent = None
    def setParent(self,parent):
        self.parent = parent
    def __le__(node1,node2):
        return(node1.mhtn <= node2.mhtn)

moves = {}
moves[1] = [2,4]
moves[2] = [1,3,5]
moves[3] = [2,6]
moves[4] = [1,5,7]
moves[5] = [2,4,6,8]
moves[6] = [3,5,9]
moves[7] = [4,8]
moves[8] = [5,7,9]
moves[9] = [6,8]

manhattan = {1:{1:0,2:1,3:2,4:1,5:2,6:3,7:2,8:3,9:4}, \
                 2:{1:1,2:0,3:1,4:2,5:1,6:2,7:3,8:2,9:3}, \
                 3:{1:2,2:1,3:0,4:3,5:2,6:1,7:4,8:3,9:2}, \
                 4:{1:1,2:2,3:3,4:0,5:1,6:2,7:1,8:2,9:3}, \
                 5:{1:2,2:1,3:2,4:1,5:0,6:1,7:2,8:1,9:2}, \
                 6:{1:3,2:2,3:1,4:2,5:1,6:0,7:3,8:2,9:1}, \
                 7:{1:2,2:3,3:4,4:1,5:2,6:3,7:0,8:1,9:2}, \
                 8:{1:3,2:2,3:3,4:2,5:1,6:2,7:1,8:0,9:1}, \
                 9:{1:4,2:3,3:2,4:3,5:2,6:1,7:2,8:1,9:0} }


def main():
    board = {}
    board[1] = 1
    board[2] = 3
    board[3] = 6
    board[4] = 5
    board[5] = 2
    board[6] = 4
    board[7] = 7
    board[8] = 0
    board[9] = 8

    node = Node(board,0)
    printNode(node)
    startGame(node)
    global no_nodes 
    print "it took",no_nodes,"moves to reach the goal"
    #backtrace()
    return 0

def startGame(node):
    global visited
    tmp = node.parent
    #if not tmp == None:
    #  visited.append(tmp.contents) 
    global no_nodes
    if(no_nodes > 1000):
        print "CRIT ERR"
        return -1
    if(isGoal(node)):
        return 0
    node.mhtn = calculate(node)
    temp = []
    global moves
    for i in getKids(node,moves):
        temp.append(i)
        i.setParent(node)
        print "#",calculate(i)
    h.heapify(temp)
    global path
    a = h.heappop(temp)
    #path = list(set(path))
    if not tmp == None:
      if(a.contents == tmp.contents):
           a = h.heappop(temp)
    #if not tmp == None:
    #  while a.contents in visited:
    #     a = h.heappop(temp)
    path.append(a)
    printNode( a)
    print "###",calculate(a),no_nodes
    no_nodes += 1
    startGame(a)

def calculate(node):
    # lookup table for Manhattan Distances
    global manhattan
    distance = 0
    # for every square not containing the blank, add the Manhattan Distance
    # to the cost
    for i in range(1,10):
        if node.contents[i] != 0:
            distance += manhattan[i][node.contents[i]]
    return distance
# goal test for our search
def isGoal(node):
    if (node.contents[1] == 1) and \
       (node.contents[2] == 2) and \
       (node.contents[3] == 3) and \
       (node.contents[4] == 4) and \
       (node.contents[5] == 5) and \
       (node.contents[6] == 6) and \
       (node.contents[7] == 7) and \
       (node.contents[8] == 8):
        return True
    else:
        return False

def getKids(node, moves):
    kids = []
    child = Node(None, 0)   #child node to be put in list of children
    board = node.contents
    for square in board.keys():
        if board[square] == 0:
            #generate a child node for each of the possible squares that the
            #blank square can be moved to
            for move in moves[square]:
                temp = board.copy()
                temp[square] = board[move]
                temp[move] = board[square]
                child = Node(temp,0)
                child.mhtn = calculate(child)
                kids.append(child)                    
    print 'Kids len',len(kids)
    return kids
def printNode(node):
    for i in range(1,4):
        print node.contents[i], " ",
    print '\n'
    for i in range(4,7):
        print node.contents[i], " ",
    print '\n'
    for i in range(7,10):
        print node.contents[i], " ",
    print '\n'
    print '--------------'



if __name__ == "__main__":
    main()
